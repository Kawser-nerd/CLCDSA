#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cassert>
#include <map>

using namespace std;

vector<pair<int,int> > hoge(vector<int> b){
	int n=b.size();
	vector<int> chk(n);
	vector<pair<int,int> > ret;
	for(int i=0;i<n;i++){
		if(chk[i])continue;
		if(b[i]==0)continue;
		int cnt=0;
		for(int j=0;j<n;j++){
			if(chk[j])continue;
			if(b[j]!=b[i] && (b[j]&b[i])!=0)assert(0);
			if(b[j]==b[i]){cnt++;chk[j]=1;}
		}
		ret.push_back(make_pair(cnt,__builtin_popcount(b[i])));
	}
	return ret;
}

map<pair<vector<pair<int,int> >,int>,int> memo;

int dp(vector<pair<int,int> > a,int slack){
	if(memo.count(make_pair(a,slack))>0)return memo[make_pair(a,slack)];
	int ret;
	if(a.empty())ret=0;
	else{
		ret=101010;
		for(int b=1;b<(1<<(a.size()));b+=2){
			for(int i=0;i+1<a.size();i++)if(((b>>i)&1)==0 && ((b>>(i+1))&1)==1 && a[i]==a[i+1])continue;
			vector<pair<int,int> > na;
			int xs=0,ys=0;
			for(int i=0;i<a.size();i++){
				if(((b>>i)&1)==1){xs+=a[i].first;ys+=a[i].second;}
				else na.push_back(a[i]);
			}
			int s=max(xs,ys);
			if(s>slack){
				//for(int i=0;i<a.size();i++)printf("(%d %d) ",a[i].first,a[i].second);
				//printf(" slack=%d : b=%d : too large\n",slack,b);
				continue;
			}else{
				//for(int i=0;i<a.size();i++)printf("(%d %d) ",a[i].first,a[i].second);
				//printf(" slack=%d : b=%d : new=%d (%dx%d)\n",slack,b,slack-s,xs,ys);
				ret=min(ret,s*s-s+dp(na,slack-s));
			}
		}
	}
	
	//for(int i=0;i<a.size();i++)printf("(%d %d) ",a[i].first,a[i].second);
	//printf(" slack=%d : %d\n",slack,ret);
	return memo[make_pair(a,slack)]=ret;
}
/*
int sol(vector<pair<int,int> > a,int n){
	sort(a.begin(),a.end());
	return n+dp(a,n);
}
*/

int sol0(vector<pair<int,int> > a,int n){
	sort(a.begin(),a.end());
	return n+dp(a,n);
}

int sol(vector<pair<int,int> > a,int n){
	vector<pair<int,int> > b;
	int s=0,t=0;
	for(int i=0;i<a.size();i++)if(a[i].first==a[i].second){
		s+=a[i].first*a[i].second;
		t+=a[i].first;
	}else b.push_back(a[i]);
	return s+sol0(b,n-t);
}


main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		int n;
		scanf("%d",&n);
		vector<int> pat(n);
		int init=0;
		for(int i=0;i<n;i++){
			char buf[30];
			scanf("%s",buf);
			pat[i]=0;
			for(int j=0;j<n;j++)pat[i]=pat[i]*2+(buf[j]-'0');
			for(int j=0;j<n;j++)if(buf[j]=='1')init++;
		}
		
		for(;;){
			bool progress=false;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(pat[i]==pat[j] || (pat[i]&pat[j])==0)continue;
					pat[i]=pat[j]=(pat[i]|pat[j]);
					progress=true;
				}
			}
			if(!progress)break;
		}
		vector<pair<int,int> > a=hoge(pat);

		printf("%d\n",sol(a,n)-init);
	}
}