#include <stdio.h>

void main()
{
  int x,y,r,s,t,a[9];
  r=8;
  s=0;
  x=0;
  do{
    a[++x]=r;
    do{
    ++s;
    y=x;
    while(y>1)
      if (!(t=a[x]-a[--y]) || x-y==(t<0 ? -t:t)){
      y=0;
      while(!--a[x])
        --x;
      }
	  printf("%d,%d\n",y,s);
    } while(y!=1);
  } while(x!=r);
  printf("%d",s);
}