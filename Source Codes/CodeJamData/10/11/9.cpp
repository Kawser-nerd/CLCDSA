#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int maxsize=100+5;

int n,m;
char A[maxsize][maxsize];

bool check(char key)
{
	for (int i=0;i<n;i++) for (int j=0;j<n;j++)
		for (int dx=-1;dx<=1;dx++) for (int dy=-1;dy<=1;dy++) if (abs(dx)+abs(dy)>0)
		{
			bool isGood=true;
			for (int d=0;d<m;d++)
			{
				int x=i+dx*d;
				int y=j+dy*d;
				if (x<0 || x>=n || y<0 || y>=n || A[x][y]!=key)
				{
					isGood=false;
					break;
				}
			}
			if (isGood) return true;
		}
	return false;
}
int main()
{
	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		scanf("%d%d",&n,&m);
		for (int j=n-1;j>=0;j--) 
		{
			for (int i=0;i<n;i++)
			{
				char c;
				do{scanf("%c",&c);
				}while (c!='.' && c!='R' && c!='B');
				A[i][j]=c;
			}
			int p=n-1;
			for (int i=n-1;i>=0;i--)
				if (A[i][j]!='.')
					A[p--][j]=A[i][j];
			for (;p>=0;p--)
				A[p][j]='.';
		}
		bool bR=check('R');
		bool bB=check('B');
		if (!bR && !bB)
			printf("Neither\n");
		else if (bR && !bB)
			printf("Red\n");
		else if (!bR && bB)
			printf("Blue\n");
		else
			printf("Both\n");
		fflush(stdout);
	}
	return 0;
}
