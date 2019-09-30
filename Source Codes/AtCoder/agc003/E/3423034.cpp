#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long lint;
const int N=1e5+2;
int n,m;
lint st[N],cnt[N],add_p[N];

template <class T> inline T nxi(){
	T x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

int main(){
#ifndef ONLINE_JUDGE
//	freopen("a.in","r",stdin);
#endif
	n=nxi<int>(),m=nxi<int>();
	int pt=1;
	st[1]=n;
	for(int i=1;i<=m;++i){
		const lint x=nxi<lint>();
		while(pt&&st[pt]>=x) --pt;
		st[++pt]=x;
	}
	m=pt;
	cnt[m]=1;
	st[m+1]=(lint)2e18;
	for(int i=m;i>1;--i){
		lint cur=st[i];
		for(int tp=i-1;cur>=st[1];cur%=st[tp]){
			tp=std::upper_bound(st+1,st+tp+1,cur)-st-1;
			cnt[tp]+=cur/st[tp]*cnt[i];
		}
		add_p[cur]+=cnt[i];
	}
	for(int i=st[1];i;--i){
		add_p[i-1]+=add_p[i];
	}
	for(int i=1;i<=n;++i){
		printf("%lld\n",(st[1]>=i?cnt[1]:0)+add_p[i]);
	}
	return 0;
}