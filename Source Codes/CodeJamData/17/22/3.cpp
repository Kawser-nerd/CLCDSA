#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <string>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char ans[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int n;
		scanf("%d",&n);
		int R,O,Y,G,B,V;
		scanf("%d %d %d %d %d %d",&R,&O,&Y,&G,&B,&V);
		if(Y==V&&Y>0)
		{
			if(n!=Y+V) puts("IMPOSSIBLE");
			else
			{
				for(int i=0;i<n;i++)
				{
					if(i%2==0) printf("Y");
					else printf("V");
				}puts("");
			}
		}
		else if(B==O&&B>0)
		{
			if(n!=B+O) puts("IMPOSSIBLE");
			else
			{
				for(int i=0;i<n;i++)
				{
					if(i%2==0) printf("B");
					else printf("O");
				}puts("");
			}
		}
		else if(R==G&&R>0)
		{
			if(n!=R+G) puts("IMPOSSIBLE");
			else
			{
				for(int i=0;i<n;i++)
				{
					if(i%2==0) printf("R");
					else printf("G");
				}puts("");
			}
		}
		else
		{
			if(Y<=V&&V>0) puts("IMPOSSIBLE");
			else if(B<=O&&O>0) puts("IMPOSSIBLE");
			else if(R<=G&&G>0) puts("IMPOSSIBLE");
			else
			{
				R-=G;
				B-=O;
				Y-=V;
				if(2*max(R,max(B,Y))>R+B+Y) puts("IMPOSSIBLE");
				else
				{
					string ret="";
					for(int i=0;i<R;i++) ret+="R";
					for(int i=0;i<B;i++)
					{
						int pos=-1;
						for(int j=0;j<ret.size();j++) if(ret[j]==ret[(j+1)%ret.size()]) pos=j;
						string nxt="";
						for(int j=0;j<=pos;j++) nxt+=ret[j];
						nxt+="B";
						for(int j=pos+1;j<ret.size();j++) nxt+=ret[j];
						ret=nxt;
					}
					for(int i=0;i<Y;i++)
					{
						int pos=-1;
						for(int j=0;j<ret.size();j++) if(ret[j]!='Y'&&ret[(j+1)%ret.size()]!='Y') pos=j;
						for(int j=0;j<ret.size();j++) if(ret[j]==ret[(j+1)%ret.size()]) pos=j;
						string nxt="";
						for(int j=0;j<=pos;j++) nxt+=ret[j];
						nxt+="Y";
						for(int j=pos+1;j<ret.size();j++) nxt+=ret[j];
						ret=nxt;
					}
					for(int i=0;i<ret.size();i++)
					{
						if(ret[i]=='R')
						{
							string nxt="";
							for(int j=0;j<=i;j++) nxt+=ret[j];
							for(int j=0;j<G;j++) nxt+="GR";
							for(int j=i+1;j<ret.size();j++) nxt+=ret[j];
							ret=nxt;
							break;
						}
					}
					for(int i=0;i<ret.size();i++)
					{
						if(ret[i]=='Y')
						{
							string nxt="";
							for(int j=0;j<=i;j++) nxt+=ret[j];
							for(int j=0;j<V;j++) nxt+="VY";
							for(int j=i+1;j<ret.size();j++) nxt+=ret[j];
							ret=nxt;
							break;
						}
					}
					for(int i=0;i<ret.size();i++)
					{
						if(ret[i]=='B')
						{
							string nxt="";
							for(int j=0;j<=i;j++) nxt+=ret[j];
							for(int j=0;j<O;j++) nxt+="OB";
							for(int j=i+1;j<ret.size();j++) nxt+=ret[j];
							ret=nxt;
							break;
						}
					}
					printf("%s\n",ret.c_str());
				}
			}
		}
	}
	return 0;
}
