#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	float b;
	int a=3;
	char buf[128];
	float x;
	x=atol(gets(buf,128));
	b=((int)x)%2;
	while (b==0)
	{
		if(((int)x)%2==0)
		{
			printf("%d",2);
			printf("*");
		}
		else
		{
			while(a>=floor(x/a)+1)
			{
				if(x%a==0)
				{
					printf("%d",a);
					printf("*");
					x=x/a;
				}
				else a=a+2;
			}
		}
	}
}
