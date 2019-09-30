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
const int maxn=1002;
int bestx,besty,ca,ti,n,i,x[maxn],y[maxn],now;
char ch[maxn];
bool found;
void check(int a,int b){
	int i;
	fr(i,1,n)
		if(max(abs(a-x[i]),abs(b-y[i]))&1){
			if(ch[i]!='#')
				return;
		}
		else
			if(ch[i]!='.')
				return;				
	if(!found||a>bestx||a==bestx&&b>besty){
		found=true;
		bestx=a;
		besty=b;
	}
}
int main(){
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n)
			cin>>x[i]>>y[i]>>ch[i];
		found=false;
		check(0,0);
		fr(now,1,20002){
			if(found)
				break;
			fr(i,-now,now){
				check(i,now-abs(i));
				check(i,-(now-abs(i)));
			}
		}		
		if(found)
			cout<<"Case #"<<ti<<": "<<bestx<<" "<<besty<<endl;
		else
			cout<<"Case #"<<ti<<": Too damaged"<<endl;
	}
}

