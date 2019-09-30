#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std;

const int N = 511;
int n,m;
char s[N][N];

int main() {
	scanf("%d%d", &n, &m);
	For(i, 1, n) scanf("%s", s[i]+1);
	For(i, 1, n) {
	  For(j, 1, m) 
	    if(j == 1) putchar('.');
	    else if(j == m) putchar('#');
	    else if( i&1 ) putchar('#');
	    else if(s[i][j]=='#') putchar('#');
	    else putchar('.');
	  putchar('\n');
	}
	putchar('\n');
	For(i, 1, n) {
	  For(j, 1, m) 
	  	if(j == m) putchar('.');
	  	else if(j == 1) putchar('#');
	  	else if( !(i&1) ) putchar('#');
	  	else if(s[i][j]=='#') putchar('#');
	  	else putchar('.');
	  putchar('\n');
	}
	return 0;
}