#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int	read()//?????????? 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int n,s[105],dp[10005];
int main(){
	n=read(); 
	for(int i=1;i<=n;i++)s[i]=read(); dp[0]=true;
	for(int i=1;i<=n;i++){
		for(int j=100*i;j>=s[i];j--)dp[j]|=dp[j-s[i]];
	}
	for(int j=100*n;j;j--)if(dp[j]&&(j%10)){
		writeln(j); return 0;
	}
	writeln(0);
}