#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
#define N 1010
int n,m,d[N];char s[N];bool v[40][40];
map<char,int> A;
void add(char a,char b)
{
	v[a-'a'][b-'a']=1;
	if(A.find(a)!=A.end())
	{
		v[A[a]+26][b-'a']=1;
		if(A.find(b)!=A.end())
			v[a-'a'][A[b]+26]=1,
			v[A[a]+26][A[b]+26]=1;
	}else
		if(A.find(b)!=A.end())
			v[a-'a'][A[b]+26]=1;
}
int main()
{
	A['o']=0,A['i']=1,A['e']=3,A['a']=4,A['s']=5,A['t']=7,A['b']=8,A['g']=9;
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d%s",&m,s),n=strlen(s);
		memset(v,0,sizeof v);
		for(int i=0;i<n-1;i++)add(s[i],s[i+1]);
		int S=0;
		for(int i=0;i<36;i++)
			for(int j=0;j<36;j++)if(v[i][j])S++;
		memset(d,0,sizeof d);
		for(int i=0;i<36;i++)
			for(int j=0;j<36;j++)if(v[i][j])d[i]++,d[j]--;
		int T=100000;
		for(int i=0;i<36;i++)
			for(int j=0;j<36;j++)
			{
				d[i]++,d[j]--;
				int U=0;
				for(int k=0;k<36;k++)
					if(d[k]>0)U+=d[k];
				T=min(T,U);
				d[i]--,d[j]++;
			}
		printf("Case #%d: %d\n",__,S+T+1);
	}
	return 0;
}
