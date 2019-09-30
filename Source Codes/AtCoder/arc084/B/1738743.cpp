#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
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
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=100005;
int k,dist[N],ans,oo=1000000005;
priority_queue<pair<int,int> > q;
#include<string>
int main(){
	ans=oo;
    cin>>k;
    for(int i=0;i<k;i++)dist[i]=oo;
    dist[0]=0;
    q.push(mp(0,0));
    while(!q.empty()){
        pair<int,int> zs=q.top(); q.pop();
        zs.first=-zs.first;
        if(zs.first>dist[zs.second])continue;
        for(int i=0;i<10;i++){
        	int u=(zs.second*10+i)%k;
			if(zs.second!=0&&u==0)ans=min(ans,dist[zs.second]+i);
			if(dist[zs.second]+i<dist[u]){
            dist[u]=dist[zs.second]+i;
            q.push(mp(-dist[u],u));
        }}
    }
    cout<<ans<<endl;
}