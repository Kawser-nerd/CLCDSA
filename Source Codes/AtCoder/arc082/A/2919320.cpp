#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	int n;
	memset(a,0,sizeof(a));
	int maxn = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int k;
		scanf("%d",&k);
		a[k]++;
		a[k+1]++;
		if(k!=0)
		a[k-1]++;
		maxn = max(maxn,a[k]);
		maxn = max(maxn,a[k+1]);
		if(k!=0)
		maxn = max(maxn,a[k-1]);
	}
	printf("%d",maxn);
}