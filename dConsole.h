#ifndef DCONSOLE_H
#define DCONSOLE_H

int dGetLineBox (char * s,int max,int width,int x,int y);

void dConsoleRedraw ();

void dConsolePut(const char * str);
void dConsolePutChar (char c);

int dGetLine (char * s,int max);

int dPrintf (const char * format,...);

void dConsoleCls ();

#define printf dPrintf

#endif