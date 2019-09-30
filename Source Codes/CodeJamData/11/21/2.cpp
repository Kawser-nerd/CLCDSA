#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

string s[111];
double wp[111];
double owp[111];
double oowp[111];
int n;

double getWP(int i,int k){
	int g = 0;
	int w = 0;
	REP(j,n)if(j!=k){
		if(s[i][j]!='.') g++;
		if(s[i][j]=='1') w++;
	}
	return double(w)/g;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n) cin>>s[i];

		REP(i,n){
			int g = 0;
			int w = 0;
			REP(j,n){
				if(s[i][j]!='.') g++;
				if(s[i][j]=='1') w++;
			}
			wp[i] = double(w)/g;

			double ss = 0;
			int num = 0;
			REP(j,n)if(s[i][j]!='.'){
				ss+=getWP(j,i);
				num++;
			}
			owp[i] = ss / num;
		}
		REP(i,n){
			double ss = 0;
			int num = 0;
			REP(j,n)if(s[i][j]!='.'){
				ss+=owp[j];
				num++;
			}
			oowp[i] = ss / num;
		}

		printf("Case #%d:\n",TC+1);
		REP(i,n) printf("%.10lf\n",wp[i]/4 + owp[i]/2 + oowp[i]/4);
	}
	return 0;
}