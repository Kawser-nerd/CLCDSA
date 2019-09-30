#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int N,M;
int x[2000],y[2000],p[2000];
int bx[2],by[2],nx[2],ny[2];
int rela(int x,int y,int u,int v)
{
	int ret=0;
	if (x<u) ret+=2;
	if (y<v) ret++;
	return ret;
}
int main()
{
	int t,T;
	freopen("A-large.in","r",stdin);
	freopen("largeaoutput.txt","w",stdout);
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		int q,c;
		fprintf(stderr,"test #%d\n",t);
		scanf("%d",&N);
		for (q=0;q<N;q++) 
		{
			char tp[10];
			scanf("%d %d %s",x+q,y+q,tp);
			if (tp[0]=='N') 
			{
				p[q]=0;
				scanf("%s",tp);
			}
			else p[q]=1;
		}
		bx[0]=by[0]=1000005,by[1]=bx[1]=0;
		c=0;
		for (q=0;q<N;q++)
		{
			if (!p[q]) continue;
			c++;
			if (bx[0]>x[q]) bx[0]=x[q];
			if (bx[1]<x[q]) bx[1]=x[q];
			if (by[0]>y[q]) by[0]=y[q];
			if (by[1]<y[q]) by[1]=y[q];
		}
		printf("Case #%d:\n",t);
		if (c==0) //# of bird =0 only unkwon and not bird
		{
			scanf("%d",&M);
			for (q=0;q<M;q++)
			{
				int u,v,w;
				scanf("%d %d",&u,&v);
				for (w=0;w<N;w++) if (x[w]==u && y[w]==v) break;
				if (w<N) printf("NOT BIRD\n");
				else printf("UNKNOWN\n");
			}
		}
		else
		{
			nx[0]=ny[0]=0,nx[1]=ny[1]=1000005;
			for (q=0;q<N;q++) 
			{
				if (p[q]) continue;
				if (y[q]>=by[0] && y[q]<=by[1])
				{
					if (x[q]<bx[0] && x[q]>nx[0]) nx[0]=x[q];
					if (x[q]>bx[1] && x[q]<nx[1]) nx[1]=x[q];
				}
				if (x[q]>=bx[0] && x[q]<=bx[1])
				{
					if (y[q]<by[0] && y[q]>ny[0]) ny[0]=y[q];
					if (y[q]>by[1] && y[q]<ny[1]) ny[1]=y[q];
				}
			}
			if (t==5)
			{
				fprintf(stderr,"%d %d %d %d\n",bx[0],bx[1],by[0],by[1]);
				fprintf(stderr,"%d %d %d %d\n",nx[0],nx[1],ny[0],ny[1]);
			}
			scanf("%d",&M);
			for (q=0;q<M;q++)
			{
				int u,v,w;
				scanf("%d %d",&u,&v);
				if (bx[0]<=u && u<=bx[1] && by[0]<=v && v<=by[1]) printf("BIRD\n");
				else if (nx[0]>=u || ny[0]>=v || nx[1]<=u || ny[1]<=v) printf("NOT BIRD\n");
				else 
				{
					if (bx[0]<=u && u<=bx[1]) printf("UNKNOWN\n");
					else if (by[0]<=v && v<=by[1]) printf("UNKNOWN\n");
					else
					{
						int a=rela(bx[0],by[0],u,v);
						for (w=0;w<N;w++) 
						{
							if (p[w]) continue;
							int b=rela(bx[0],by[0],x[w],y[w]);
							if (a==b && b==rela(x[w],y[w],u,v)) break;
						}
						if (w<N) printf("NOT BIRD\n");
						else printf("UNKNOWN\n");
					}
				}
			}
		}
	}
	return 0;
}