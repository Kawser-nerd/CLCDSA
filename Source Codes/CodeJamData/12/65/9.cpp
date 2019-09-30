#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<stdio.h>
#include<cstring>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=42;
int ca,ti,i,n,tot,now,state,l[maxn],r[maxn];
bool s[maxn][1<<12];
int main(){
	freopen("e1.in","r",stdin);
	freopen("e1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n-1)
			cin>>l[i]>>r[i];
		memset(s,0,sizeof(s));
		tot=0;
		now=1;
		state=0;
		while(now!=n&&!s[now][state]){
			s[now][state]=true;
			state^=(1<<(now-1));
			if((state>>(now-1))&1)
				now=l[now];
			else
				now=r[now];
			tot++;			
		}
		if(now==n)	
			cout<<"Case #"<<ti<<": "<<tot<<endl;
		else
			cout<<"Case #"<<ti<<": Infinity"<<endl;		
	}
}

