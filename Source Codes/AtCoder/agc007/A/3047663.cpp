#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int h,w;
	cin>>h>>w;
	int a[11][11]={};
	int cnt=0;
	FORQ(i,1,h){
		string s;
		cin>>s;
		FORQ(j,1,w){
			if(s[j-1]=='#')a[i][j]=1;
			cnt+=a[i][j];
		}
	}
	FOR(i,0,(1<<20)){
		int x=1,y=1,c=0;
		FOR(j,0,20){
			if((i>>j)&1){//r
				if(a[x][y+1]){
					c++;
					y++;
				}
			}else{//d
				if(a[x+1][y]){
					c++;
					x++;
				}
			}
		}
		//if(x==h&&y==w)cout<<i<<" x:"<<x<<" y:"<<y<<" c"<<c<<endl;
		if(x==h&&y==w&&cnt==c+1){
			cout<<"Possible";
			return 0;
		}
	}
	cout<<"Impossible";
    return 0;
}