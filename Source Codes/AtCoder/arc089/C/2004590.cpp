#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
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
int ff,ans[105][105][3],a,b,dist[105][105],tong[105][105];
int main(){
	a=read(); b=read();
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)dist[i][j]=read();
	for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)for(int o=0;o<=100;o++){
		int f=1;
		for(int k=1;k<=a&&f;k++){
			for(int l=1;l<=b&&f;l++)if(i*k+j*l+o<dist[k][l])f=0;
		}
		if(!f)continue;
		for(int k=1;k<=a;k++){
			for(int l=1;l<=b;l++){
				if(i*k+j*l+o==dist[k][l]){
					ans[k][l][0]=i+1; ans[k][l][1]=j+1; ans[k][l][2]=o;
				}
			}
		} break;
	}
	ff=1;
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)if(!ans[i][j][0])ff=0;
	if(!ff){
		puts("Impossible"); return 0;
	}
	puts("Possible");
	int m=200; for(int i=1;i<=a;i++)for(int j=1;j<=b;j++){
		if(!tong[ans[i][j][0]][ans[i][j][1]])m++; tong[ans[i][j][0]][ans[i][j][1]]=1;
	}
	cout<<202<<" "<<m<<endl; memset(tong,0,sizeof(tong));
	for(int i=1;i<=100;i++)cout<<i<<" "<<i+1<<" X\n";
	for(int i=102;i<=201;i++)cout<<i<<' '<<i+1<<" Y\n";
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)if(ans[i][j][0]){
		if(!tong[ans[i][j][0]][ans[i][j][1]]){
			cout<<ans[i][j][0]<<" "<<203-ans[i][j][1]<<" "<<ans[i][j][2]<<endl;
		}
		tong[ans[i][j][0]][ans[i][j][1]]=1;
	}
	puts("1 202");
}