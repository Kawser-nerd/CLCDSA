#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#define ll long long
#define debug cout<<"debug"<<endl;
using namespace std;
const int maxn=2e5+50;
char s[maxn];
int c[maxn],cnt[maxn],ok,n;
bool vis[maxn];
vector<int> loc[30];///vector???main??? ??tle 

int lowbit(int x){
	return x&(-x);
}

void add(int x,int d){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=d;
	}
}

int sum(int x){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)){
		ret+=c[i];
	}
	return ret;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		ok=0; 

		for(int i=1;i<=n;i++){
			cnt[s[i]-'a']++;
			loc[s[i]-'a'].push_back(i);
		}
		for(int i=0;i<26;i++){
			if(cnt[i]%2) ok++;
		}
		if(ok>1){
			printf("-1\n");
			return 0;
		}
		for(int i=1;i<=n+1;i++){
			add(i,1);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int c=s[i]-'a';
			int loc_right=loc[c].back();
			if(loc_right==i){
				ans+=(sum(n)-sum(loc_right))>>1;///????????????? ?????? 
			}
			else{
				ans+=sum(n)-sum(loc_right);
			}
			loc[c].pop_back();
			add(i,-1); 
			add(loc_right,-1);
			vis[i]=vis[loc_right]=true;
		}
		printf("%lld\n",ans);
		//memset(s,0,sizeof(s));
	return 0;
}