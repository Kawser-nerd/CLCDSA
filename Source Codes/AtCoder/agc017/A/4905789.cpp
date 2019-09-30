#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
typedef long long ll;

long long po(int x,int y){
	long long ans=1;
	for(int i=0;i<y;i++)ans*=x;
	return ans;
}
int main(){
    int N,p;
    int a[60];
    cin>>N>>p;
    REP(i,N) cin>>a[i];
    bool flag=true;
    REP(i,N) {
        if(a[i]%2!=0){
            flag=false;
            break;
        } 
    }
    ll cnt=1;
   // cout<<v.size()<<w.size()<<pow(2,0)<<endl;
    if(!flag){
   cnt=po(2,N-1);
    cout<<cnt<<endl;
    }
    else {
        if(p==0) cout<<po(2,N)<<endl;
        else cout<<0<<endl;
    }

    return 0;
}