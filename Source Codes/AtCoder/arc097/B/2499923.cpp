#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#define Max zhi5968
typedef long long ll;
using namespace std;
const int maxn=100000+10;
set <int> st[100000+20];  
int a[maxn];   
int p[maxn];
int find(int x){  
    return x==p[x]?x:p[x]=find(p[x]);
}  
int main(){ 
	int n,m,i;
	cin>>n>>m;
    for(int i=0;i<n;i++)  
   		p[i]=i;  
   	for(i=1;i<=n;i++)
   		cin>>a[i];
   	for(i=0;i<m;i++)
   	{
   		int t1,t2;
		cin>>t1>>t2;
		int x=find(t1),y=find(t2);
		if(x!=y) p[y]=x;			
	}
	for(i=0;i<maxn;i++)
		find(i);
	int ans=0;
	for(i=1;i<=n;i++)
		if(p[i]==p[a[i]])
			ans++;
	cout<<ans<<endl;
    return 0;  
}