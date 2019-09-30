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
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()//?????????? 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
int n,m;
const int N=400005;
int s1[N],s2[N],f[N];
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		s1[i]=read();s2[i]=read();
		if(s1[i]==1)f[s2[i]]=1;
	}
	for(int i=1;i<=m;i++)if(s2[i]==n&&f[s1[i]]){
		puts("POSSIBLE"); return 0;
	}
	puts("IMPOSSIBLE");
}