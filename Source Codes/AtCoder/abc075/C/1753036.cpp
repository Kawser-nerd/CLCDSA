#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std ;
inline int read() {
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; }
	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; }
	return x * f ;
}

const int N = 61;
int n,m,sum,flag;
struct node{
	int x,y;
}e[N];
int fa[N];

inline int find(int x) {
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

inline void Union(int x,int y) {
	x = find(x); 
	y = find(y);
	if(x!=y) fa[x] = y;
}

int main() {
	n = read(); m = read();
	For(i, 1, m) e[i].x=read(), e[i].y=read();
	For(T, 1, m) {
		flag = 0;
		For(i, 1, n) fa[i] = i;
		For(i, 1, m) {
			if(i==T) continue;
			Union(e[i].x,e[i].y);
		} 
		For(i, 1, n) fa[i] = find(fa[i]);
		For(i, 1, n) if(fa[i]!=fa[1]) flag = 1;
		sum+=flag;
	}
	printf("%d\n",sum);
	return 0;
}