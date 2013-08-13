/* stdio.h library for large systems - small embedded systems use clibrary.c instead */
#include <errno.h>
#include "../interpreter.h"

static int ZeroValue = 0;

int StrPutChar(char * dest,char c)
{
	*dest++ = c;
	*dest = '\0';
	return 1;
}

int StrPutStr(char * dest,const char * scr)
{
	int l;
	for (l=0;*scr;++l)
		*dest++ = *scr++;
	*dest = '\0';
	return l;
}

void GenericPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs, char * str)
{
    char *FPos;
    struct Value *NextArg = Param[0];
    struct ValueType *FormatType;
    int ArgCount = 1;
    int LeftJustify = FALSE;
    int ZeroPad = FALSE;
    int FieldWidth = 0;
    char *Format = Param[0]->Val->Pointer;
    
	int l;

    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            if (*FPos == '-')
            {
                /* a leading '-' means left justify */
                LeftJustify = TRUE;
                FPos++;
            }
            
            if (*FPos == '0')
            {
                /* a leading zero means zero pad a decimal number */
                ZeroPad = TRUE;
                FPos++;
            }
            
            /* get any field width in the format */
            while (isdigit((int)*FPos))
                FieldWidth = FieldWidth * 10 + (*FPos++ - '0');
            
            /* now check the format type */
            switch (*FPos)
            {
                case 's': FormatType = CharPtrType; break;
                case 'd': case 'u': case 'x': case 'b': case 'c': FormatType = &IntType; break;
                case 'f': FormatType = &FPType; break;
                case '%': StrPutChar(str,'%');++str;FormatType = NULL; break;
                case '\0': FPos--; FormatType = NULL; break;
                default:  StrPutChar(str,*FPos);++str; FormatType = NULL; break;
            }
            
            if (FormatType != NULL)
            { 
                /* we have to format something */
                if (ArgCount >= NumArgs)
				{
					l = StrPutStr(str,"XXX");str+=l;
				}
                else
                {
                    NextArg = (struct Value *)((char *)NextArg + MEM_ALIGN(sizeof(struct Value) + TypeStackSizeValue(NextArg)));
                    if (NextArg->Typ != FormatType && 
                            !((FormatType == &IntType || *FPos == 'f') && IS_NUMERIC_COERCIBLE(NextArg)) &&
                            !(FormatType == CharPtrType && (NextArg->Typ->Base == TypePointer || 
                                                             (NextArg->Typ->Base == TypeArray && NextArg->Typ->FromType->Base == TypeChar) ) ) )
					{
						l = StrPutStr(str,"XXX");str+=l;
					}
                    else
                    {
                        switch (*FPos)
                        {
                            case 's':
                            {
                                char *Str;
                                
                                if (NextArg->Typ->Base == TypePointer)
                                    Str = NextArg->Val->Pointer;
                                else
                                    Str = &NextArg->Val->ArrayMem[0];
                                    
                                if (Str == NULL)
								{
									l = StrPutStr(str,"NULL");str+=l;
								}
                                else
								{
									l = StrPutStr(str,Str);str+=l;
								}
                                break;
                            }
                            case 'd': l = sprintf(str,"%d",ExpressionCoerceInteger(NextArg));str+=l; break;
                            case 'u': l = sprintf(str,"%u",ExpressionCoerceUnsignedInteger(NextArg));str+=l; break;
                            case 'x': l = sprintf(str,"%x",ExpressionCoerceUnsignedInteger(NextArg));str+=l; break;
                            case 'b': l = sprintf(str,"%b",ExpressionCoerceUnsignedInteger(NextArg));str+=l; break;
                            case 'c': l = sprintf(str,"%c",ExpressionCoerceUnsignedInteger(NextArg));str+=l; break;
                            case 'f': l = sprintf(str,"%f",ExpressionCoerceFP(NextArg));str+=l; break;
                        }
                    }
                }
                
                ArgCount++;
            }
        }
        else
		{
            StrPutChar(str,*FPos);++str;
		}
    }
}

void StdioSprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    char * buf;

    buf = Param[0]->Val->Pointer;

    GenericPrintf(Parser, ReturnValue, Param+1, NumArgs-1,buf);

    ReturnValue->Val->Integer = strlen(buf);
}

void StdioPuts(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{

    dConsolePut((const char*)Param[0]->Val->Pointer);
	dConsolePutChar ('\n');

    ReturnValue->Val->Integer = 0;
}

void Bdisp_PutDisp_DD();

void StdioPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    char buf[256];

    GenericPrintf(Parser, ReturnValue, Param, NumArgs,buf);

	dConsolePut (buf);//Bdisp_PutDisp_DD();
	
    ReturnValue->Val->Integer = strlen(buf);
}
void StdioCls(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	dConsoleCls();
}
void StdioGets(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	char *buf;

	buf = Param[0]->Val->Pointer;

	dGetLine(buf,Param[1]->Val->Integer);
	dConsolePut (buf);
	dConsolePutChar('\n');

	ReturnValue->Val->Pointer = buf;
}

/* all stdio functions */
struct LibraryFunction StdioFunctions[] =
{
    { StdioSprintf		,"int sprintf(char *, char *,...);" },
	{ StdioPuts			,"int puts(char *);"},
	{ StdioGets			,"char * gets(char *,int);"},
	{ StdioCls			,"void cls();"},
	{ StdioPrintf		,"int printf(char *,...);"},
    { NULL,         NULL }
};

/* creates various system-dependent definitions */
void StdioSetupFunc(void)
{

    /* define NULL, TRUE and FALSE */
    if (!VariableDefined(TableStrRegister("NULL")))
        VariableDefinePlatformVar(NULL, "NULL", &IntType, (union AnyValue *)&ZeroValue, FALSE);
}
