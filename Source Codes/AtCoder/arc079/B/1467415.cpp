#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()//?????????? 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
long long a[1005],k,T,n,ans;
int main(){
	//freopen("std.in","w",stdout);
	k=read();
	n=50; 
	for(int i=1;i<=n;i++)a[i]=k/n+n-1;
	k%=n;
	//for(int i=1;i<=k;i++)a[i]+=(k-i+1);
	writeln(n);
	for(int i=1;i<=n;i++){
		write(a[i]-k+(i<=k?(k-i)+2:0)); putchar(' ');
	}
}