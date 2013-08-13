#include "../picoc.h"
#include "../interpreter.h"
#include <fxlib.h>
#include <stdlib.h>

/* mark where to end the program for platforms which require this */
jmp_buf PicocExitBuf;

void PlatformCleanup()
{
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen, const char *Prompt)
{
	return NULL;
}

/* get a character of interactive input */
int PlatformGetCharacter()
{
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh, union OutputStreamInfo *Stream)
{
    dConsolePutChar(OutCh);
}
/* fx-9860 file ctrl*/

typedef FONTCHARACTER fontc;

fontc * CharToFont(const char * cfname,fontc * ffname)
{
	int i,len = strlen(cfname);
	for(i=0; i<len ;++i)
		ffname[i] = cfname[i];
	ffname[i]=0;
	return ffname;
}

char * FontToChar(const fontc *ffname,char *cfname)
{
	int i = 0;
	while((cfname[i]=ffname[i])!=0)++i;
	return cfname;
}

int	OpenFile (const char * cfname,int mode)
{
	fontc ffname[32];

	CharToFont(cfname,ffname);

	return Bfile_OpenFile(ffname,mode);
}

/* read a file into memory */
char *PlatformReadFile(const char *FileName)
{
    char *	ReadText;
    int		BytesRead,FileSize;
	int		FileHandle;

	FileHandle = OpenFile(FileName,_OPENMODE_READ);
	
	if (FileHandle < 0)
		ProgramFail(NULL, "cannot open\n");
	FileSize = Bfile_GetFileSize(FileHandle);

    ReadText = malloc(FileSize + 1);

    if (ReadText == NULL)
        ProgramFail(NULL, "out of memory\n");

    BytesRead = Bfile_ReadFile(FileHandle,ReadText,FileSize,0);

    ReadText[BytesRead] = '\0';
    
	Bfile_CloseFile(FileHandle);

	return ReadText;
}

/* read and scan a file for definitions */
void PicocPlatformScanFile(const char *FileName)
{
    char *SourceStr = PlatformReadFile(FileName);

    PicocParse(FileName, SourceStr, strlen(SourceStr), TRUE, FALSE, TRUE);
}

/* exit the program */
void PlatformExit(int RetVal)
{
    PicocExitValue = RetVal;
    longjmp(PicocExitBuf, 1);
}

