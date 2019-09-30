#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
int ans,ca,ti,i,n,k,le[128],ri[128];
char chg[128];
bool all[128][128];
string s;
void add(char a,char b){
	if(all[a][b])
		return;
	all[a][b]=true;
	le[a]++;
	ri[b]++;
	n++;
}
int main(){
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	memset(chg,0,sizeof(chg));
	chg['o']='0';
	chg['i']='1';
	chg['e']='3';
	chg['a']='4';
	chg['s']='5';
	chg['t']='7';
	chg['b']='8';
	chg['g']='9';
	cin>>ca;
	fr(ti,1,ca){
		memset(all,0,sizeof(all));
		memset(le,0,sizeof(le));
		memset(ri,0,sizeof(ri));
		n=0;
		cin>>k;
		cin>>s;
		fr(i,0,(int)s.size()-2){
			add(s[i],s[i+1]);
			if(chg[s[i]])
				add(chg[s[i]],s[i+1]);
			if(chg[s[i+1]])
				add(s[i],chg[s[i+1]]);
			if(chg[s[i]]&&chg[s[i+1]])
				add(chg[s[i]],chg[s[i+1]]);
		}
		ans=n*2;
		fr(i,0,127)
			ans-=min(le[i],ri[i]);
		if(ans==n)
			ans++;
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}