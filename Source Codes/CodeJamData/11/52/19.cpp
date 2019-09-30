#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=1001;
const int maxv=10001;
int a[maxn];
int cnt[maxv];
int v[maxv];
int n;

void init(){
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	return;
}

int calc(){
	if (n==0){
		return 0;
	}
	int ans=(1<<15);
	int l=0;
	for (int i=0;i<maxv;i++){
		sort(v,v+l);
		int cur;
		for (cur=0;cur<l;cur++){
			if (cnt[i]==0){
				break;
			}
			v[cur]++;
			cnt[i]--;
		}
		while (1){
			if (l<=cur){
				break;
			}
			ans=min(ans,v[l-1]);
			l--;
		}
		while (1){
			if (cnt[i]==0){
				break;
			}
			l++;
			v[l-1]=1;
			cnt[i]--;
		}
	}
	for (int i=0;i<l;i++){
		ans=min(ans,v[i]);
	}
	return ans;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %d\n",i,calc());
	}
	return 0;
}
