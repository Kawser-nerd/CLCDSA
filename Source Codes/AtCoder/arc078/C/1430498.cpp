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
int a[100];
char ch[10];
inline void print(){int i,zs=0,flag=1;
//a[9]=3; a[8]=2; a[6]=1;
	for(i=1;i<=9;i++)if(a[i]){
		break;
	}for(int j=9;j>=i;j--){if(a[j]!=9)flag=0;zs=zs*10+a[j];} 
	for(int j=i;j;j--){
		printf("? %d\n",zs+1); fflush(stdout);
		scanf("%s",&ch);
		if((ch[0]=='Y')^flag){
			putchar('!'); putchar(' ');
			for(i=9;i>=j;i--)putchar(a[i]+48); return;
		}
		zs*=10;
	}
}
inline void dfs(int p){
	if(!p){
		print(); return ;
	}
	int l=0,r=9,i; if(p==9)l++;
	while(l<r){
		int mid=(l+r)>>1;
		putchar('?'); putchar(' '); 
		for(i=9;i>p;i--)putchar(a[i]+48); 
		putchar(mid+48); for(i=p;i;i--)putchar('9'); 
		puts(""); fflush(stdout);
		scanf("%s",&ch);
		if(ch[0]=='Y')r=mid; else l=mid+1;
	}
	a[p]=l;
	dfs(p-1);
}
int main(){
	printf("? %d\n",999999999); fflush(stdout);
		scanf("%s",&ch); if(ch[0]=='N'){
			puts("! 1000000000"); return 0;
		}
	dfs(9);
	return 0;
} ./Main.cpp:34:14: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
                scanf("%s",&ch);
                       ~~  ^~~
./Main.cpp:53:14: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
                scanf("%s",&ch);
                       ~~  ^~~
./Main.cpp:61:14: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
                scanf("%s",&ch); if(ch[0]=='N'){
                       ~~  ^~~
3 warnings generated.