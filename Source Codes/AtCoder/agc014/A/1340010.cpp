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
inline void write(int a) {
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a) {
	write(a);
	puts("");
}
inline int	read() { //??????????
	int x = 0;
	char ch = getchar();
	bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int main() {
	int a=read(),b=read(),c=read(),ans=0;
	while(!((a&1)||(b&1)||(c&1))) {
		int s1=a>>1,s2=b>>1,s3=c>>1;
		a=s2+s3;
		b=s1+s3;
		c=s1+s2;
		ans++; if(ans>10000000){
			puts("-1"); return 0;
		}
	}
	writeln(ans);
}