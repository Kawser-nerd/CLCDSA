#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
int a[110],b[110];
int main(){
	int n,m,p,t;
	cin>>n;
	int sum = 0;
	for (int i = 1;i <= n; ++i){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	cin >> m;
	int ans;
	while (m--){
		cin>>p>>t;
		ans = sum - a[p] + t;
		printf("%d\n",ans);
	}
	return 0;
}