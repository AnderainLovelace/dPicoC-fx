#include "picoc.h"
#include "interpreter.h"

/* the value passed to exit() */
int PicocExitValue = 0;

/* initialise everything */
void PicocInitialise(int StackSize)
{
   	HeapInit(StackSize);		//printf("heap init\n");
    TableInit();				//printf("table init\n");
    VariableInit();				//printf("varible init\n");
    LexInit();					//printf("lex init\n");
    TypeInit();					//printf("type init\n");
    IncludeInit();				//printf("include init\n");
    LibraryInit();				//printf("library init\n");
}

/* free memory */
void PicocCleanup()
{
    PlatformCleanup();
    IncludeCleanup();
    ParseCleanup();
    LexCleanup();
    VariableCleanup();
    TypeCleanup();
    TableStrFree();
    HeapCleanup();
}

/* platform-dependent code for running programs */

#define CALL_MAIN_NO_ARGS_RETURN_VOID "main();"
#define CALL_MAIN_WITH_ARGS_RETURN_VOID "main(__argc,__argv);"
#define CALL_MAIN_NO_ARGS_RETURN_INT "__exit_value = main();"
#define CALL_MAIN_WITH_ARGS_RETURN_INT "__exit_value = main(__argc,__argv);"

void PicocCallMain(int argc, char **argv)
{
    /* check if the program wants arguments */
    struct Value *FuncValue = NULL;

    if (!VariableDefined(TableStrRegister("main")))
        ProgramFail(NULL, "main() is not defined");
        
    VariableGet(NULL, TableStrRegister("main"), &FuncValue);
    if (FuncValue->Typ->Base != TypeFunction)
        ProgramFail(NULL, "main is not a function - can't call it");

    if (FuncValue->Val->FuncDef.NumParams != 0)
    {
        /* define the arguments */
        VariableDefinePlatformVar(NULL, "__argc", &IntType, (union AnyValue *)&argc, FALSE);
        VariableDefinePlatformVar(NULL, "__argv", CharPtrPtrType, (union AnyValue *)&argv, FALSE);
    }

    if (FuncValue->Val->FuncDef.ReturnType == &VoidType)
    {
        if (FuncValue->Val->FuncDef.NumParams == 0)
            PicocParse("startup", CALL_MAIN_NO_ARGS_RETURN_VOID, strlen(CALL_MAIN_NO_ARGS_RETURN_VOID), TRUE, TRUE, FALSE);
        else
            PicocParse("startup", CALL_MAIN_WITH_ARGS_RETURN_VOID, strlen(CALL_MAIN_WITH_ARGS_RETURN_VOID), TRUE, TRUE, FALSE);
    }
    else
    {
        VariableDefinePlatformVar(NULL, "__exit_value", &IntType, (union AnyValue *)&PicocExitValue, TRUE);
    
        if (FuncValue->Val->FuncDef.NumParams == 0)
            PicocParse("startup", CALL_MAIN_NO_ARGS_RETURN_INT, strlen(CALL_MAIN_NO_ARGS_RETURN_INT), TRUE, TRUE, FALSE);
        else
            PicocParse("startup", CALL_MAIN_WITH_ARGS_RETURN_INT, strlen(CALL_MAIN_WITH_ARGS_RETURN_INT), TRUE, TRUE, FALSE);
    }
}

void PrintSourceTextErrorLine(const char *FileName, const char *SourceText, int Line, int CharacterPos)
{
    PlatformPrintf("%s:%d:", FileName, Line, CharacterPos);
}


/* display the source line and line number to identify an error */
void PlatformErrorPrefix(struct ParseState *Parser)
{
    if (Parser != NULL)
        PrintSourceTextErrorLine(Parser->FileName, Parser->SourceText, Parser->Line, Parser->CharacterPos);
}

/* exit with a message */
void ProgramFail(struct ParseState *Parser, const char *Message, ...)
{
    va_list Args;

    PlatformErrorPrefix(Parser);
    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
    va_end(Args);
    PlatformPrintf("\n");
    PlatformExit(1);
}

/* like ProgramFail() but gives descriptive error messages for assignment */
void AssignFail(struct ParseState *Parser, const char *Format, struct ValueType *Type1, struct ValueType *Type2, int Num1, int Num2, const char *FuncName, int ParamNo)
{
    PlatformErrorPrefix(Parser);
    PlatformPrintf("can't %s ", (FuncName == NULL) ? "assign" : "set");   
        
    if (Type1 != NULL)
        PlatformPrintf(Format, Type1, Type2);
    else
        PlatformPrintf(Format, Num1, Num2);
    
    if (FuncName != NULL)
        PlatformPrintf(" in argument %d of call to %s()", ParamNo, FuncName);
        
    ProgramFail(NULL, "");
}

/* exit lexing with a message */
void LexFail(struct LexState *Lexer, const char *Message, ...)
{
    va_list Args;

    PrintSourceTextErrorLine(Lexer->FileName, Lexer->SourceText, Lexer->Line, Lexer->CharacterPos);
    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
    va_end(Args);
    PlatformPrintf("\n");
    PlatformExit(1);
}

/* printf for compiler error reporting */
void PlatformPrintf(const char *Format, ...)
{
    va_list Args;
    
    va_start(Args, Format);
    PlatformVPrintf(Format, Args);
    va_end(Args);
}

void PlatformVPrintf(const char *Format, va_list Args)
{
    const char *FPos;
    
    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            switch (*FPos)
            {
            case 's': PrintStr(va_arg(Args, char *)); break;
            case 'd': PrintSimpleInt(va_arg(Args, int)); break;
            case 'c': PrintCh(va_arg(Args, int)); break;
            case 't': PrintType(va_arg(Args, struct ValueType *)); break;
#ifndef NO_FP
            case 'f': PrintFP(va_arg(Args, double)); break;
#endif
            case '%': PrintCh('%'); break;
            case '\0': FPos--; break;
            }
        }
        else
            PrintCh(*FPos);
    }
}

/* make a new temporary name. takes a static buffer of char [7] as a parameter. should be initialised to "XX0000"
 * where XX can be any characters */
char *PlatformMakeTempName(char *TempNameBuffer)
{
    int CPos = 5;
    
    while (CPos > 1)
    {
        if (TempNameBuffer[CPos] < '9')
        {
            TempNameBuffer[CPos]++;
            return TableStrRegister(TempNameBuffer);
        }
        else
        {
            TempNameBuffer[CPos] = '0';
            CPos--;
        }
    }

    return TableStrRegister(TempNameBuffer);
}
