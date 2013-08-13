#include <fxlib.h>
#include "interpreter.h"
#include "dconsole.h"
#include "picoc.h"

#define PICOC_STACK_SIZE (20*1024)

#define FILE_EXIT		0
#define FILE_EXE		1
#define FILE_SCRIPT		2
#define FILE_NOFILE 	-1

int file_view (int root,char * cfname);
/*
  setup data
*/
int stack_size;

/* in platform_fx9860.c */

typedef FONTCHARACTER fontc;

extern fontc *  CharToFont(const char * cfname,fontc * ffname);
extern char  *  FontToChar(const fontc *ffname,char *cfname);

/* timer for EXIT break */

#define TIMER_ID 2

void TimerExitBreak ()
{
	static times = 0;short unused = 0;
	int kcode1 = 0, kcode2 = 0;

	if (Bkey_GetKeyWait(&kcode1, &kcode2, KEYWAIT_HALTOFF_TIMEROFF,0,0, &unused)==KEYREP_KEYEVENT)
	{
		if ((kcode1==4)&&(kcode2==8))
			++times;
		if (times>=2)
		{
			// draw a win
			PopUpWin(3);
			locate(8,3);Print((unsigned char*)"Break!");
			locate(6,5);Print((unsigned char*)"Press [EXE]");
			while(WaitKey()!=KEY_CTRL_EXE);
			//		
			ProgramFail(0,"error:EXIT Break\n");
		}
	}
}

int AddIn_main(int isAppli, unsigned short OptionNum)
{
	char file_name[64];
	int run_main = 1;

	stack_size = PICOC_STACK_SIZE;

	switch(file_view(0,file_name))
	{
		case FILE_EXIT:
			return 0;
		case FILE_EXE:
			run_main = 1;
			break;
		case FILE_SCRIPT:
			run_main = 0;
			break;			
		case FILE_NOFILE:
			printf("no *.c file exist\npress [EXE]");
			while(WaitKey()!=KEY_CTRL_EXE);
			return 0;
		default:
			return 0;
	}

	PicocInitialise(PICOC_STACK_SIZE);

	if (PicocPlatformSetExitPoint())
 	{
		KillTimer(TIMER_ID);
 		PicocCleanup();
		while(WaitKey()!=KEY_CTRL_EXE);
 		return PicocExitValue;
 	}

	SetTimer(TIMER_ID,1000,TimerExitBreak);
	
	if (!run_main)
		PicocIncludeAllSystemHeaders();

	PicocPlatformScanFile(file_name);

 	if (run_main)
		PicocCallMain(0,0);
    
	PicocCleanup();

	WaitKey();
	
    return 1;
}


/*
	list
*/

typedef struct tag_node
{
	char				str[24]	;
	struct tag_node *	next	;
}
node;

typedef struct
{
	node	 	*head,*last	;
	int					size;
}
list;

void list_init (list * l)
{
	l->head	= NULL;
	l->last	= NULL;
	l->size	= 0;
}

void list_destory (list * l)
{
	node *line1,*line2;

	line1 = l->head;
	
	while (line1)
	{
		line2 = line1;
		line1 = line1->next ;

		free (line2);
	}

	l->head = l->last = NULL;
	l->size = 0;
}

void list_push (list * l,const char * str)
{
	if (l->size == 0)
	{
		l->head			= (node*)calloc(sizeof(node),1);
		l->last			= l->head;
	}
	else
	{
		l->last->next	= (node*)calloc(sizeof(node),1);
		l->last			= l->last->next;
	}

	strcpy(l->last->str,str);

	l->size ++;

}
/*
  graph
*/
void area_clear (int left,int top,int right,int bottom,int sel) 
{ 
	DISPBOX box; 
	box.left = left;box.top = top;box.right = right;box.bottom = bottom; 
 	if (sel != 1) 
		Bdisp_AreaClr_VRAM (&box); 
	if (sel != 0){ 
 		Bdisp_DrawLineVRAM (box.left,box.top,box.right,box.top); 
		Bdisp_DrawLineVRAM (box.left,box.bottom,box.right,box.bottom); 
		Bdisp_DrawLineVRAM (box.left,box.top,box.left,box.bottom); 
		Bdisp_DrawLineVRAM (box.right,box.top,box.right,box.bottom); 
    } 
}

/*
  draw picture
*/
void draw_picture (int x,int y,int width,int height,int mode,unsigned char * pGraph)
{
	DISPGRAPH dg;

	dg.x					= x;
	dg.y					= y;
	dg.GraphData.width		= width;
	dg.GraphData.height		= height;
	dg.GraphData.pBitmap	= pGraph;
	dg.WriteModify			= mode+1;
	dg.WriteKind			= IMB_WRITEKIND_OVER;

	Bdisp_WriteGraph_VRAM(&dg);
}
/*
  setup
*/
void setup ()
{
}

/*
  file viewer
*/
extern const unsigned char ICON_EXE[],ICON_SCP[],ICON_SET[];

#define		all_clr		Bdisp_AllClr_VRAM
#define		area_rev	Bdisp_AreaReverseVRAM
#define		putdisp		Bdisp_PutDisp_DD
#define		printxy		PrintXY
#define 	REFRESH_PART	1
#define		REFRESH_ALL		2

int file_view (int root,char * cfname)
{
	char			strtemp[32];
	fontc			fnttemp[32];
	fontc			fntpath[32];
	char			**clist;
	unsigned int	key;
	list			lfile;
	int				fh_find;
	node			*nnode;
	int				i,top,bottom,index,refresh;
	const int		h_max = 6-1;
	FILE_INFO		file_info;

	list_init(&lfile);

	sprintf(strtemp,"\\\\%s\\*.c",root ? "fls0":"crd0");
	CharToFont(strtemp,fntpath);
	

	if(Bfile_FindFirst (fntpath,&fh_find,fnttemp,&file_info)!=0)
	{
		Bfile_FindClose(fh_find);
		return -1;
	}

	do
	{
		FontToChar(fnttemp,strtemp);
		//locate(1,1);Print(strtemp);
		//WaitKey();
		//
		list_push(&lfile,strtemp);
	}
	while(Bfile_FindNext(fh_find,fnttemp,&file_info)==0);

	Bfile_FindClose(fh_find);

	clist = (char**)malloc(sizeof(char*)*lfile.size);
	
	for (i=0,nnode=lfile.head;nnode!=NULL;nnode=nnode->next,++i)
	{
		clist[i] = nnode->str;
	}

	/* select file */

	index = 0,refresh = REFRESH_ALL;
	top = 0,bottom = h_max;
	while(1)
	{
		if (refresh)
		{
			int y;

			/* draw_title && bottom */
			if (refresh == REFRESH_ALL)
			{
				char temp[32];
				all_clr();
				locate(1,1) ;Print((unsigned char*)"dPicoC Programs");
				locate(17,1);Print((const unsigned char*)(root ? "[fls]":"[crd]"));
				area_rev(0,0,127,7);

				draw_picture(  2,56,19,8,0,ICON_EXE);
				draw_picture( 23,56,19,8,0,ICON_SCP);
				draw_picture(107,56,19,8,0,ICON_SET);
			}
			else
				area_clear(0,8,127,55,0);

			if (bottom-top>h_max)bottom = top + h_max;
			if(top>index)
			{
				top = index;
				bottom = index + h_max;
			}
			if (index>bottom)
			{
				bottom = index;
				top = bottom - h_max;
			}
			if(bottom>lfile.size - 1)bottom = lfile.size - 1;

			if(top>0)
				{locate(21,2);Print((unsigned char*)"\xE6\x92");}
			if(bottom<lfile.size-1)
				{locate(21,7);Print((unsigned char*)"\xE6\x93");}

			for (i=top;i<=bottom;++i)
			{
				y = i-top+1;
				locate(2,y+1);Print((unsigned char*)clist[i]);
				if(index==i)area_rev(0,y*8,127,7+y*8);	
			}
		}
		GetKey(&key);

		if (key==KEY_CTRL_UP) 
			{if(--index<0) index = lfile.size - 1;refresh = REFRESH_PART;}
		if (key==KEY_CTRL_DOWN)
			{if(++index>lfile.size - 1) index = 0;refresh = REFRESH_PART;}
		if (key==KEY_CTRL_EXIT)
		{
			free(clist);
			list_destory(&lfile);
		
			return FILE_EXIT;
		}
		if (key==KEY_CTRL_EXE || key==KEY_CTRL_F1 || key==KEY_CTRL_F2)
		{
			sprintf(cfname,"\\\\%s\\%s",root ? "fls0":"crd0",clist[index]);
			free(clist);
			list_destory(&lfile);
			
			if (key==KEY_CTRL_F2)
				return FILE_SCRIPT;
			else
				return FILE_EXE;
		}

	}

	free(clist);
	list_destory(&lfile);

	return 0;
}

const unsigned char ICON_EXE[]= //19*8
{0xFF,0xFF,0xE0,
0x80,0x0,0x0,
0xBD,0x17,0x80,
0xA0,0xA4,0x0,
0xB8,0x47,0x0,
0xA0,0xA4,0x0,
0xBD,0x17,0x80,
0x80,0x0,0x0,};

const unsigned char ICON_SCP[]= //19*8
{0xFF,0xFF,0xE0,
0x80,0x0,0x0,
0x9E,0x73,0x80,
0xA0,0x8A,0x40,
0x9C,0x83,0x80,
0x82,0x8A,0x0,
0xBC,0x72,0x0,
0x80,0x0,0x0,};

const unsigned char ICON_SET[] = //19*8
{0xFF,0xFF,0xE0,
0xC2,0x10,0x60,
0xBE,0xFD,0xE0,
0xC6,0x1D,0xE0,
0xFA,0xFD,0xE0,
0xFA,0xFD,0xC0,
0x86,0x1D,0x80,
0xFF,0xFF,0x0,};

#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

