#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-8
#define PI 3.14159265358979323846
using namespace std;

int a[500000];
int b[500001];
int ret[500001];
int c[600001];
int tb[500001];
int N;
map<int,int> mm;
int lowbit(int n){
	return n& (-n);
}

void Modify(int n, int delta){
	while(n <= N){
		c[n] += delta;
		if(c[n]>=1000000007)
			c[n]-=1000000007;
		n += lowbit(n);
	}
}

int Sum(int n){
	int result = 0;
	while(n != 0){
		result += c[n];
		if(result>=1000000007)
			result-=1000000007;
		n -= lowbit(n);
	}
	return result;
}

int main(){
	int T,TT;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		int i,n,m,x,y,z,j;
		scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		b[0]=-1;
		tb[0]=-1;
		for(i=0;i<n;i++){
			b[i+1]=a[i%m];
			tb[i+1]=a[i%m];
			a[i%m]=((long long)x * (long long)a[i%m] + (long long)y * ((long long)i + 1)) % z;
		}
		sort(tb,tb+n+1);
		int last=-2;
		for(i=0,j=0;i<=n;i++){
			if(tb[i]!=last){
				last=tb[j]=tb[i];
				j++;
			}
		}
		N=j-1;///////////////////////////
		for(i=0;i<j;i++){
			mm[tb[i]]=i+1;
		}
		memset(ret,0,sizeof(ret));
		ret[0]=1;
		memset(c,0,sizeof(c));
		Modify(1,1);
		for(i=1;i<=n;i++){
			int p=mm[b[i]];
			ret[i]=Sum(p-1);
			Modify(p,ret[i]);
		}
		int sum=0;
		for(i=1;i<=n;i++){
			sum+=ret[i];
			if(sum>1000000007)
				sum-=1000000007;
		}
		printf("Case #%d: %d\n",TT,sum);
	}
}

