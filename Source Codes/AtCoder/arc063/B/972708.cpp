#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#define maxn 100009
#define maxm
#define PS system("pause");
using namespace std;
int a[maxn],n,T;
int b[maxn];
vector<int>c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	int cur=0;
	int mi=1e9+1;
	for(int i=1;i<=n;i++){
		if(a[i]-mi>cur){
			cur=a[i]-mi;
			ans=1;
		}
		else if(a[i]-mi==cur){
			ans++;
		}
		mi=min(a[i],mi);
	}
	printf("%d\n",ans);
	return 0;
}