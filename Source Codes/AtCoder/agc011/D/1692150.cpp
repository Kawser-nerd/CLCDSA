#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,m,rev;
char s[200009];
deque<int> q;

inline void throws()
{
	int c=q.front();
	q.pop_front();
	if(c^rev==0)
		q.push_front(1^rev);
	else
	{
		rev^=1;
		q.push_back(0^rev);
	}
}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	
	for(int i=1;i<=n;i++)
		q.push_back((s[i]=='A')?0:1);
	for(int i=1;i<=2*n && i<=m;i++)
		throws();

	if(2*n<m)
	{
		m-=2*n;
		m%=2;
		for(int i=1;i<=m;i++)
			throws();
	}
	while(!q.empty())
			putchar((q.front()^rev)+'A'),q.pop_front();
	putchar('\n');
	return 0;
} ./Main.cpp:18:6: warning: ^ has lower precedence than ==; == will be evaluated first [-Wparentheses]
        if(c^rev==0)
            ^~~~~~~
./Main.cpp:18:6: note: place parentheses around the '==' expression to silence this warning
        if(c^rev==0)
            ^
             (     )
./Main.cpp:18:6: note: place parentheses around the ^ expression to evaluate it first
        if(c^rev==0)
            ^
           (    )
1 warning generated.