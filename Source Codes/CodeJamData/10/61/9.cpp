#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int TC;
string s;
int  d[111][111];

int go(int i,int j){
	if(i>j) return 0;
	if(d[i][j]!=-1) return d[i][j];
	if(i==j) return 2;
	int res = 2 + go(i+1,j);

	for(int k=i+1;k<=j;k++)
		if(s[k] == s[i]){
			res = min(res, 1 + go(i+1,k-1) + go(k, j)-1);
		}

	return d[i][j]=res;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>TC;
	REP(tc,TC){
		cin>>s;
		CL(d,-1);
		printf("Case #%d: %d\n",tc+1,go(0,s.size()-1)+s.size());
	}


	return 0;
}