#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int h, w, n;
map<pair<int, int> , int> mp;
map<pair<int, int> , int>::iterator it;
long long ans[22];

int main() {
	scanf("%d%d%d", &h, &w, &n);
	mp.clear();
	for(int i=0;i<n;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for(int j=x;j<x+3;j++)
			for(int k=y;k<y+3;k++)
				if(j<=h && k<=w && j>=3 && k>=3)
					mp[make_pair(j, k)] ++;
	}
	memset(ans, 0, sizeof ans);
	ans[0] = 1LL*(w-2)*(h-2);
	for (it = mp.begin(); it!= mp.end(); it++) {
		int cnt = (*it).second;
		ans[cnt] ++;
		ans[0]--;
	}
	for(int i=0;i<10;i++) cout<<ans[i]<<endl;
	
	return 0;
}