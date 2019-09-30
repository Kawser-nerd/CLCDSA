#define rep(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define SCAN(k) scanf("%d",&k)
#define PI 3.14159265359
#define INF (ll)(2e18+100)
#define MOD (int)(1e9+7)
#define MAX 10000
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include<algorithm>
#include<stdio.h>
#include <set>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

int main(){
	int a[4];
	string s;
	cin>>s;
	rep(i,4) cin>>a[i];
	int k=0;
	rep(i,s.size()){
		if(a[k]==i){
			cout<<"\"";
			if(k!=3)k++;
		}
		cout<<s[i];
	}
	if(a[k]==s.size())cout<<"\"";
	cout<<endl;
	return 0;
}