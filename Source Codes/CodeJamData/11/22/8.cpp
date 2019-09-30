#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <iterator>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

#define x first
#define y second

int n,d;

pair<int,int> a[1111];

bool check(double t){
	double cur=-1e15;
	for (int i=0;i<n;i++){
		double L=a[i].x-t,R=a[i].x+t;
		double curR=max(cur+d,L)+(double)((long long)(a[i].y-1)*(long long)d);
		if (curR>R) return false;
		cur=curR;
	}
	return true;
}

void work(){
	cin >> n >> d;
	for (int i=0;i<n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a,a+n);
	double lo=0,hi=1e15;
	for (int i=0;i<100;i++){
		double mid=(lo+hi)/2;
		if (check(mid)) hi=mid;
			else lo=mid;
	}
	printf("%.15lf\n",lo);
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int t;cin >> t;
	for (int i=1;i<=t;i++){
		cout << "Case #"<< i << ": ";
		work();
	}
	//system("pause");
	return 0;
}
/*
2
3 2
0 1
3 2
6 1
2 2
0 3
1 1
*/
