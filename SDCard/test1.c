#include <stdio.h>

int main ()
{
	int i,m,k,j=0;
	for(m=3;m<=100;m++)
	{
		k=0;
		for(i=2;i<=m-1;i++)
		{
			if (m%i==0)
				{k=1;break;}
			if (k==0)
			{
				printf("%3d",m);
				j++;
				if (j%4==0)
				printf("\n");
			}
		}
	}
}