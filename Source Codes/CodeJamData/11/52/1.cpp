#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int a[2000];
int n,T,ti=0;
vector<int> now;
int num[11000];

int main(){
	for (scanf("%d",&T);T--;){
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for (int i=0;i<n;i++) scanf("%d",&a[i]),num[a[i]]++;
		int ans=1000000;
		now.clear();
		if (n==0) ans=0;
		for (int i=0;i<=10000;i++){
			sort(now.begin(),now.end());
			int z=0;
			for (;z<now.size()&&num[i]>0;num[i]--,z++)
				now[z]++;
			for (;now.size()>z;){
				ans=min(ans,now[now.size()-1]);
				now.pop_back();
			}
			for (;num[i];num[i]--) now.PB(1);
		}
		for (int i=0;i<now.size();i++) ans=min(ans,now[i]);
		printf("Case #%d: %d\n",++ti,ans);
	}
    return 0;
}
