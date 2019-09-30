#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int a[1000005];

int main(void){
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	reverse(a,a+n);
	int now=0;
	while(now+1<a[now+1] && now<n){
		now++;
	}
	ll c1=a[now]-now;
	ll c2=0;
	int nv=now;
	while(nv<a[now]){
		c2++;
		now++;
	}
	c1--;
	c2--;
	printf("%s\n",(c1%2LL==0 && c2%2LL==0)?"Second":"First");
	return 0;
}