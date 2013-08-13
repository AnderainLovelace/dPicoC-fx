/* stdio.h library for large systems - small embedded systems use clibrary.c instead */
#include <errno.h>
#include <fxlib.h>
#include "../interpreter.h"

static int ZeroValue = 0;
// AllClr
void FxlibBdisp_AllClr_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AllClr_DD();
}

void FxlibBdisp_AllClr_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AllClr_VRAM();
}
void FxlibBdisp_AllClr_DDVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AllClr_DDVRAM();
}
void FxlibBdisp_AreaClr_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AreaClr_DD(Param[0]->Val->Pointer);
}

void FxlibBdisp_AreaClr_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AreaClr_VRAM(Param[0]->Val->Pointer);
}
void FxlibBdisp_AreaClr_DDVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AreaClr_DDVRAM(Param[0]->Val->Pointer);
}
void FxlibBdisp_AreaReverseVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_AreaReverseVRAM(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer,Param[3]->Val->Integer);
}
void FxlibBdisp_GetDisp_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_GetDisp_DD(Param[0]->Val->Pointer);
}
void FxlibBdisp_GetDisp_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_GetDisp_VRAM(Param[0]->Val->Pointer);
}
void FxlibBdisp_PutDisp_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_PutDisp_DD();
}
void FxlibBdisp_PutDispArea_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_PutDispArea_DD(Param[0]->Val->Pointer);
}
void FxlibBdisp_SetPoint_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_SetPoint_DD(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer);
}
void FxlibBdisp_SetPoint_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_SetPoint_VRAM(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer);
}
void FxlibBdisp_SetPoint_DDVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_SetPoint_DDVRAM(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer);
}
void FxlibBdisp_GetPoint_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bdisp_GetPoint_VRAM(Param[0]->Val->Integer,Param[1]->Val->Integer);
}
void FxlibBdisp_WriteGraph_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_WriteGraph_DD(Param[0]->Val->Pointer);
}
void FxlibBdisp_WriteGraph_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_WriteGraph_VRAM(Param[0]->Val->Pointer);
}
void FxlibBdisp_WriteGraph_DDVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_WriteGraph_DDVRAM(Param[0]->Val->Pointer);
}

void FxlibBdisp_ReadArea_DD(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_ReadArea_DD(Param[0]->Val->Pointer,Param[1]->Val->Pointer);
}
void FxlibBdisp_ReadArea_VRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_ReadArea_VRAM(Param[0]->Val->Pointer,Param[1]->Val->Pointer);
}
void FxlibBdisp_DrawLineVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_DrawLineVRAM(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer,Param[3]->Val->Integer);
}
void FxlibBdisp_ClearLineVRAM(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bdisp_ClearLineVRAM(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Integer,Param[3]->Val->Integer);
}

void FxlibLocate		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	locate(Param[0]->Val->Integer,Param[1]->Val->Integer);
}
void FxlibPrint			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Print(Param[0]->Val->Pointer);
}
void FxlibPrintRev		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintRev(Param[0]->Val->Pointer);
}
void FxlibPrintC		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintC(Param[0]->Val->Pointer);
}
void FxlibPrintRevC		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintRevC(Param[0]->Val->Pointer);
}
void FxlibPrintLine		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintLine(Param[0]->Val->Pointer,Param[1]->Val->Integer);
}
void FxlibPrintRLine	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintRLine(Param[0]->Val->Pointer,Param[1]->Val->Integer);
}
void FxlibPrintXY		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintXY(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Pointer,Param[3]->Val->Integer);
}
void FxlibPrintMini		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PrintMini(Param[0]->Val->Integer,Param[1]->Val->Integer,Param[2]->Val->Pointer,Param[3]->Val->Integer);
}

void FxlibSaveDisp		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	SaveDisp(Param[0]->Val->Integer);
}
void FxlibRestoreDisp	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	RestoreDisp(Param[0]->Val->Integer);
}
void FxlibPopUpWin		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	PopUpWin(Param[0]->Val->Integer);
}
void FxlibBfile_OpenFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_OpenFile(Param[0]->Val->Pointer,Param[1]->Val->Integer);
}
void FxlibBfile_OpenMainMemory		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_OpenMainMemory(Param[0]->Val->Pointer);
}
void FxlibBfile_ReadFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_ReadFile(Param[0]->Val->Integer,Param[1]->Val->Pointer,Param[2]->Val->Integer,Param[3]->Val->Integer);
}
void FxlibBfile_WriteFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_WriteFile(Param[0]->Val->Integer,Param[1]->Val->Pointer,Param[2]->Val->Integer);
}
void FxlibBfile_SeekFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_SeekFile(Param[0]->Val->Integer,Param[1]->Val->Integer);
}
void FxlibBfile_CloseFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_CloseFile(Param[0]->Val->Integer);
}
void FxlibBfile_GetMediaFree		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_GetMediaFree(Param[0]->Val->Integer,Param[1]->Val->Pointer);
}
void FxlibBfile_GetFileSize			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_GetFileSize(Param[0]->Val->Integer);
}
void FxlibBfile_CreateFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_CreateFile(Param[0]->Val->Pointer,Param[1]->Val->Integer);
}
void FxlibBfile_CreateDirectory		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_CreateDirectory(Param[0]->Val->Pointer);
}
void FxlibBfile_CreateMainMemory	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_CreateMainMemory(Param[0]->Val->Pointer);
}
void FxlibBfile_RenameMainMemory	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_RenameMainMemory(Param[0]->Val->Pointer,Param[1]->Val->Pointer);
}
void FxlibBfile_DeleteFile			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_DeleteFile(Param[0]->Val->Pointer);
}
void FxlibBfile_DeleteDirectory		(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_DeleteDirectory(Param[0]->Val->Pointer);
}
void FxlibBfile_DeleteMainMemory	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_DeleteMainMemory(Param[0]->Val->Pointer);
}
void FxlibBfile_FindFirst			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_FindFirst(Param[0]->Val->Pointer,Param[1]->Val->Pointer,Param[2]->Val->Pointer,Param[3]->Val->Pointer);
}
void FxlibBfile_FindNext			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_FindNext(Param[0]->Val->Integer, Param[1]->Val->Pointer, Param[2]->Val->Pointer);
}
void FxlibBfile_FindClose			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = Bfile_FindClose(Param[0]->Val->Integer);
}

void FxlibBkey_Set_RepeatTime			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bkey_Set_RepeatTime(Param[0]->Val->Integer,Param[1]->Val->Integer);
}
void FxlibBkey_Get_RepeatTime			(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bkey_Get_RepeatTime(Param[0]->Val->Pointer,Param[1]->Val->Pointer);
}
void FxlibBkey_Set_RepeatTime_Default	(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Bkey_Set_RepeatTime_Default();
}
void FxlibGetKey						(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ReturnValue->Val->Integer = GetKey(Param[0]->Val->Pointer);
}
void FxlibSleep(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Sleep(Param[0]->Val->Integer);
}

const char FxlibDefs[] = "\
typedef struct {int left;int top;int right;int bottom;} DISPBOX;\
typedef struct tag_GRAPHDATA{\
	int  width;\
	int  height;\
	unsigned char  *pBitmap;\
} GRAPHDATA;\
typedef struct tag_DISPGRAPH{\
	int				x;\
	int				y;\
	GRAPHDATA		GraphData;\
	unsigned char	WriteModify;\
	unsigned char	WriteKind;\
} DISPGRAPH;\
typedef struct tag_FILE_INFO{\
    unsigned short  id;\
    unsigned short  type;\
    unsigned long   fsize;\
    unsigned long   dsize;\
    unsigned int    property;\
    unsigned long   address;\
} FILE_INFO;\
typedef unsigned short FONTCHARACTER;\
";

struct LibraryFunction FxlibFunctions[] =
{
	{ FxlibBdisp_AllClr_DD			,"void Bdisp_AllClr_DD(); "},
	{ FxlibBdisp_AllClr_VRAM		,"void Bdisp_AllClr_VRAM(); "},
	{ FxlibBdisp_AllClr_DDVRAM		,"void Bdisp_AllClr_DDVRAM(); "},

	{ FxlibBdisp_AreaClr_DD			,"void Bdisp_AreaClr_DD(DISPBOX *); "},
	{ FxlibBdisp_AreaClr_VRAM		,"void Bdisp_AreaClr_VRAM(DISPBOX *); "},
	{ FxlibBdisp_AreaClr_DDVRAM		,"void Bdisp_AreaClr_DDVRAM(DISPBOX *); "},

	{ FxlibBdisp_AreaReverseVRAM	,"void Bdisp_AreaReverseVRAM(int,int,int,int);"},

	{ FxlibBdisp_GetDisp_DD			,"void Bdisp_GetDisp_DD(unsigned char *);"},
	{ FxlibBdisp_GetDisp_VRAM		,"void Bdisp_GetDisp_VRAM(unsigned char *);"},

	{ FxlibBdisp_PutDisp_DD			,"void Bdisp_PutDisp_DD();"},
	{ FxlibBdisp_PutDispArea_DD		,"void Bdisp_PutDispArea_DD(DISPBOX*);"},
	
	{ FxlibBdisp_SetPoint_DD		,"void Bdisp_SetPoint_DD(int,int,unsigned char);"},
	{ FxlibBdisp_SetPoint_VRAM		,"void Bdisp_SetPoint_VRAM(int,int,unsigned char);"},
	{ FxlibBdisp_SetPoint_DDVRAM	,"void Bdisp_SetPoint_DDVRAM(int,int, unsigned char);"},
	{ FxlibBdisp_GetPoint_VRAM		,"int  Bdisp_GetPoint_VRAM(int,int);"},

	{ FxlibBdisp_WriteGraph_DD		,"void Bdisp_WriteGraph_DD(DISPGRAPH*); "},
	{ FxlibBdisp_WriteGraph_VRAM	,"void Bdisp_WriteGraph_VRAM(DISPGRAPH *); "},
	{ FxlibBdisp_WriteGraph_DDVRAM	,"void Bdisp_WriteGraph_DDVRAM(DISPGRAPH *); "},

	{ FxlibBdisp_ReadArea_DD		,"void Bdisp_ReadArea_DD(DISPBOX *,unsigned char *);"},
	{ FxlibBdisp_ReadArea_VRAM		,"void Bdisp_ReadArea_VRAM(DISPBOX *,unsigned char *);"},

	{ FxlibBdisp_DrawLineVRAM		,"void Bdisp_DrawLineVRAM(int,int,int,int);"},
	{ FxlibBdisp_ClearLineVRAM		,"void Bdisp_ClearLineVRAM(int,int,int,int);"},

	{ FxlibLocate					,"void locate(int,int);"},
	{ FxlibPrint					,"void Print(unsigned char*);"},
	{ FxlibPrintRev					,"void PrintRev(unsigned char*);"},
	{ FxlibPrintC					,"void PrintC(unsigned char*);"},
	{ FxlibPrintRevC				,"void PrintRevC(unsigned char*);"},
	{ FxlibPrintLine				,"void PrintLine(unsigned char*,int);"},
	{ FxlibPrintRLine				,"void PrintRLine(unsigned char*,int);"},
	{ FxlibPrintXY					,"void PrintXY(int,int,unsigned char*,int);"},
	{ FxlibPrintMini				,"void PrintMini(int,int,unsigned char*,int);"},
	
	{ FxlibSaveDisp					,"void SaveDisp(unsigned char);"},
	{ FxlibRestoreDisp				,"void RestoreDisp(unsigned char);"},
	{ FxlibPopUpWin 				,"void PopUpWin(int);"},

	{ FxlibBfile_OpenFile			,"int Bfile_OpenFile(FONTCHARACTER*,int);"},
	{ FxlibBfile_OpenMainMemory		,"int Bfile_OpenMainMemory(unsigned char *);"},
	{ FxlibBfile_ReadFile			,"int Bfile_ReadFile(int,void*,int,int);"},
	{ FxlibBfile_WriteFile			,"int Bfile_WriteFile(int,void *,int);"},
	{ FxlibBfile_SeekFile			,"int Bfile_SeekFile(int,int);"},
	{ FxlibBfile_CloseFile			,"int Bfile_CloseFile(int);"},
	{ FxlibBfile_GetMediaFree		,"int Bfile_GetMediaFree(int,int*);"},
	{ FxlibBfile_GetFileSize		,"int Bfile_GetFileSize(int);"},
	{ FxlibBfile_CreateFile			,"int Bfile_CreateFile(FONTCHARACTER *);"},
	{ FxlibBfile_CreateDirectory	,"int Bfile_CreateDirectory(FONTCHARACTER *);"},
	{ FxlibBfile_CreateMainMemory	,"int Bfile_CreateMainMemory(unsigned char *);"},
	{ FxlibBfile_RenameMainMemory	,"int Bfile_RenameMainMemory(unsigned char *,unsigned char *);"},
	{ FxlibBfile_DeleteFile			,"int Bfile_DeleteFile(FONTCHARACTER *);"},
	{ FxlibBfile_DeleteDirectory	,"int Bfile_DeleteDirectory(FONTCHARACTER *);"},
	{ FxlibBfile_DeleteMainMemory	,"int Bfile_DeleteMainMemory(unsigned char *);"},
	{ FxlibBfile_FindFirst			,"int Bfile_FindFirst(FONTCHARACTER *,int *,FONTCHARACTER *,FILE_INFO *);"},
	{ FxlibBfile_FindNext			,"int Bfile_FindNext(int,FONTCHARACTER *, FILE_INFO *);"},
	{ FxlibBfile_FindClose			,"int Bfile_FindClose(int);"},

	{ FxlibBkey_Set_RepeatTime			,"void Bkey_Set_RepeatTime(long,long);"},
	{ FxlibBkey_Get_RepeatTime			,"void Bkey_Get_RepeatTime(long *, long *);"},
	{ FxlibBkey_Set_RepeatTime_Default	,"void Bkey_Set_RepeatTime_Default();"},
	{ FxlibGetKey						,"int GetKey(unsigned int *);"},

	{ FxlibSleep					, "void Sleep(int);"},

	{ NULL,         NULL }
};


void FxlibSetupFunc(void)
{
}
