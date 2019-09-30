#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define COUT(a) cout << a;
#define ENDL cout << "\n";
int main() {
    int n,m,a,b,sum=0,all=0;
    scanf("%d\n",&n);
    int t[n];
    REP(i,n) {
        scanf("%d",&t[i]);
        all+=t[i];
    }
    scanf("%d\n",&m);
    vector<pair<int,int> > drink(m);
    REP(i,m) {
        scanf("%d %d\n",&a,&b);
        drink[i] = make_pair(a,b);
    }
    REP(i,m){
        COUT(drink[i].second - t[drink[i].first-1] + all)
        ENDL
    }
}