#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P;

int main() {
    long n; cin >> n;
    ll a[n];
    for (auto &x : a) cin >> x;

    ll ans=0;
    while (a[0]>=2){
        ans++; a[0]-=2;
    }
    for(int i=1; i<n; i++){
        while (a[i-1]>0 && a[i]>0){
            ans++; a[i-1]--; a[i]--;
        }
        while (a[i]>=2){
            ans++; a[i]-=2;
        }
    }
    cout << ans << endl;
}