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
#include<map>
#include<cmath>
const int N=200005;
map<int,int> M;
map<int,int>::iterator it;
int n,k,a[N],que[N],r,ans;
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)M[a[i]]++;
	for(it=M.begin();it!=M.end();it++){
		que[++r]=it->second;
	}
	sort(&que[1],&que[r+1]);
	for(int i=1;i+k<=r;i++){
		ans+=que[i];
	}
	cout<<ans<<endl;
}