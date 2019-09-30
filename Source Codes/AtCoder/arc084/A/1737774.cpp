#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=100005;
long long n,a[3][N],f[3][N],sum[3][N];
int main(){
	n=read();
	for(long long i=0;i<3;i++)for(long long j=1;j<=n;j++)a[i][j]=read();
	sort(&a[1][1],&a[1][n+1]); sort(&a[2][1],&a[2][n+1]); sort(&a[0][1],&a[0][n+1]);
	for(long long i=1;i<=n;i++){f[0][i]=1; sum[0][i]=i;}
	for(long long i=1;i<3;i++){
		for(long long j=1;j<=n;j++){
			long long t=lower_bound(&a[i-1][1],&a[i-1][n+1],a[i][j])-&a[i-1][0];
			t--;
			f[i][j]=sum[i-1][t]; sum[i][j]=sum[i][j-1]+f[i][j];
		}
	}
	cout<<sum[2][n]<<endl;
}