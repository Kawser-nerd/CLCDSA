#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char steprcd[1000];
int stepcnt=0;
int DX,DY;

int jump(char direct,int X,int Y)
{
	int PY,PX;
	char dir[4];
	if(direct!=0)
	{
		stepcnt++;
		switch(direct)
		{
			case 'E':
				X+=stepcnt;
				steprcd[stepcnt]='E';
				break;
			case 'S':
				Y-=stepcnt;
				steprcd[stepcnt]='S';
				break;
			case 'W':
				X-=stepcnt;
				steprcd[stepcnt]='W';
				break;
			case 'N':
				Y+=stepcnt;
				steprcd[stepcnt]='N';
		}
	}

	if(X==DX && Y==DY) return 0;

	if(stepcnt<50)
	{
		PY=DY-Y;
		PX=DX-X;
		if(abs(PY)>=abs(PX))
		{
			if(PY>0)
			{
				if(PX>0)
				{
					memcpy(dir,"NEWS",4);
				}else
				{
					memcpy(dir,"NWES",4);
				}
			}else
			{
				if(PX>0)
				{
					memcpy(dir,"SEWN",4);
				}else
				{
					memcpy(dir,"SWEN",4);
				}
			}
		}else
		{
			if(PX>0)
			{
				if(PY>0)
				{
					memcpy(dir,"ENSW",4);
				}else
				{
					memcpy(dir,"ESNW",4);
				}
			}else
			{
				if(PY>0)
				{
					memcpy(dir,"WNSE",4);
				}else
				{
					memcpy(dir,"WSNE",4);
				}
			}
		}

		if(jump(dir[0],X,Y)==0) return 0;
		if(jump(dir[1],X,Y)==0) return 0;
		if(jump(dir[2],X,Y)==0) return 0;
		if(jump(dir[3],X,Y)==0) return 0;
	}
	
	stepcnt--;
	//printf("%.*s failed\n",stepcnt,steprcd+1);
	return -1;
}
			
int main()
{
	int T=0;
	int i,j,k,c;

	scanf("%d",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%d%d",&DX,&DY);

		stepcnt=0;
		
		if(jump(0,0,0)!=0)
		{
			fprintf(stderr,"error\n");
		}
		
		printf("Case #%d: %.*s\n",c,stepcnt,steprcd+1);
	}
}





