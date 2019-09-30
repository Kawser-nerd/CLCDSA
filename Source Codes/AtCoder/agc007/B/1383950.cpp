#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int maxn = 200010;
int A[maxn],B[maxn],P[maxn],N;

inline int gi()
{
	char ch; int ret = 0,f = 1;
	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
	if (ch == '-') f = -1,ch = getchar();
	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
	return ret*f;
}

int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	N = gi();
	for (int i = 1;i <= N;++i) P[i] = gi();
	for (int i = 1;i <= N;++i) A[i] = i*20001;
	for (int i = 1;i <= N;++i) B[i] = (N-i+1)*20001;
	for (int i = 1;i <= N;++i) A[P[i]] += i;
	for (int i = 1;i < N;++i) printf("%d ",A[i]); printf("%d\n",A[N]);
	for (int i = 1;i < N;++i) printf("%d ",B[i]); printf("%d\n",B[N]);
	return 0;
}