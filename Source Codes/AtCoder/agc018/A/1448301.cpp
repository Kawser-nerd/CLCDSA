#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
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
int n,k; 
inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	n=read(); k=read(); int zs=read(); int mmax=zs; 
	for(int i=2;i<=n;i++){
		int s1=read(); zs=gcd(s1,zs); mmax=max(mmax,s1);
	}
	if(mmax<k||(k%zs!=0))puts("IMPOSSIBLE");else puts("POSSIBLE");
}