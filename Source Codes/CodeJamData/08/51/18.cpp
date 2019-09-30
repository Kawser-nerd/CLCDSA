#include <stdio.h>
#include <string.h>

int tc, ntc;

bool v[6001][6001];
bool h[6001][6001];
bool mark[6001][6001];
int L;

char buf[100];
int len;

void proc(int& cx, int& cy, int& cd)
{
	int i;
	for (i=0; i<len; i++)
	{
		if (buf[i] == 'F')
		{
			//printf("%d %d\n",cy,cx);
			if (cd == 0)
			{
				v[cy][cx] = 1;
				cy++;
			}
			else if (cd == 1)
			{
				h[cy][cx] = 1;
				cx++;
			}
			else if (cd == 2)
			{
				cy--;
				v[cy][cx] = 1;
			}
			else if (cd == 3)
			{
				cx--;
				h[cy][cx] = 1;
			}
		}
		else if (buf[i] == 'R') cd = (cd+1)%4;
		else if (buf[i] == 'L') cd = (cd+3)%4;
	}	
}

void domark1(bool ar[6001][6001], int y, bool rev)
{
	int i, j;
	
	int last = -1;
	int cnt = 0;
	for (i=0; i<=6000; i++)
	{
		if ((!rev && ar[y][i]) || (rev && ar[i][y]))
		{
			cnt++;			
			if (cnt%2 == 1 && cnt != 1)
			{				
				for (j=last; j<i; j++) 
				{
					if (!rev) mark[y][j] = true;
					else mark[j][y] = true;
				}
				
			}
			last = i;
		}
	}
}

void domark(bool ar[6001][6001], bool rev)
{
	int i;
	for (i=0; i<6000; i++)
		domark1(ar, i, rev);
		
}

int main()
{
	int i, j;
	int num;
	
	int cx, cy, cd;
	
	scanf("%d",&ntc);
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		memset(mark, 0, sizeof(mark));
				
		cx = 3000; cy = 3000; cd = 0;
			
		scanf("%d",&L);
		while (L--)
		{
			scanf("%s",buf);
			scanf("%d",&num);
			len = strlen(buf);
			
			for (i=0; i<num; i++)
				proc(cx,cy,cd);
		}
		
		domark(v, 0);
		domark(h, 1);		
		
		res = 0;
		for (i=0; i<=6000; i++) for (j=0; j<=6000; j++) 
		{
			if (mark[i][j]) res++;
				//printf("%d %d\n",i,j);
			//if (h[i][j]) printf("%d %d\n",i,j);
		}
		
		printf("Case #%d: %d\n",tc,res);
		fprintf(stderr,"Case #%d: %d\n",tc,res);
	}			
}