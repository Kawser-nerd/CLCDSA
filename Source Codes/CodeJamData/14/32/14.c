#include <stdio.h>
#include <string.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void perm(int [],int,int);
int v[128],list[128],r;
char s[100][128];
int main()
{
	//freopen("input","r",stdin);
	int t,T,i,j,l,n;
	char c;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			list[i]=i;
			scanf("%s",s[i]);
		}
		r = 0;
		perm(list,0,n-1);
		printf("Case #%d: %d\n",t,r);
	}
	return 0;
}

void perm(int list[],int i,int n)
{
    int j,temp;
    char *p,c,cp;
    if(i==n)
    {
	cp = *s[list[0]];
	for(c='a';c<='z';c++) v[c]=0;
        for(j=0;j<=n;j++)
        {
        	p = s[list[j]];
		while(*p)
		{
			if(*p!=cp)
			{
				if (v[*p]!=0) {return;}
				else {v[cp] = 1;cp = *p;}
			}
			p ++;
		}
        }
	r ++;        
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            SWAP(list[i],list[j],temp);
            perm(list,i+1,n);
            SWAP(list[i],list[j],temp);
        }
    }
}
