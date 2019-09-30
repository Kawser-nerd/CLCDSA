#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack> 
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define LL long long
#define N 100100
#define MOD 1000000007
#define FOR(i,l,r) for (int i = (l); i <= (r); i ++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define INF 0x7fffffff
#define pb push_back
#define X first
#define Y second
using namespace std;
int a[N],d[N];
int main(){
	int n;
	scanf("%d",&n);
	LL sum = 0;
	FOR(i,1,n){
		scanf("%d",&a[i]);
		sum += (LL)a[i];
	}
	LL s = (LL)(1 + n) * n / 2;
	if (sum % s != 0) printf("NO\n");
	else{
		a[n + 1] = a[1];
		int flag = 1;
		FOR(i,1,n){
			d[i] = a[i] - a[i + 1];
			LL t = sum / s;
			if ((d[i] + t) % n != 0 || d[i] + t < 0){
			   flag = 0;
			   break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	
}