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
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=8005;
int r1,r2,n,sum,que1[N],que2[N],flag;
char ch[N];
bool zs[N<<1],dp1[16005],dp2[16005];
int main(){
	scanf("%s",&ch);
	n=strlen(ch); int x=read(),y=read(); int i; ch[n++]='T';
	for(i=0;ch[i]!='T';i++)x--;
	for(i++;i<n;i++)if(ch[i]=='T'){
		if(flag){
			que1[++r1]=sum; sum=0;
		}else{
			que2[++r2]=sum; sum=0;
		}
		flag^=1;
	}else sum++;
	dp1[8000]=dp2[8000]=1;
	for(int i=1;i<=r1;i++){
		for(int j=0;j<=16000;j++)if(j>=que1[i]&&dp1[j-que1[i]])zs[j]=1; else zs[j]=0;
		for(int j=0;j<=16000;j++){if(j+que1[i]<=16000&&dp1[j+que1[i]])zs[j]=1; dp1[j]=zs[j];}
	}
	for(int i=1;i<=r2;i++){
		for(int j=0;j<=16000;j++)if(j>=que2[i]&&dp2[j-que2[i]])zs[j]=1; else zs[j]=0;
		for(int j=0;j<=16000;j++){if(j+que2[i]<=16000&&dp2[j+que2[i]])zs[j]=1; dp2[j]=zs[j];}
	}//cout<<x<<" "<<y<<endl;
	if(dp1[x+8000]&&dp2[y+8000]){
		puts("Yes");
	} else puts("No");
} ./Main.cpp:39:13: warning: format specifies type 'char *' but the argument has type 'char (*)[8005]' [-Wformat]
        scanf("%s",&ch);
               ~~  ^~~
1 warning generated.