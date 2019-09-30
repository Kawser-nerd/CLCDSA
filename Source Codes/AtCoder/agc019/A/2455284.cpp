#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second

using namespace std;

int main(){

    ll q,h,s,d,n;
    cin >> q >> h >>s >> d >> n;

    if(q*4<=2*h && 4*q <= s && 8*q <= d) cout << 4*q*n;
    else if(2*h <= s && 4*h <= d) cout << 2*h*n;
    else if(2*s <= d) cout << s*n;
    else{
        if(n%2 == 0) cout << d*n/2;
        else if(q*4<=2*h && 4*q <= s) cout << (n-1)*d/2 + q*4;
        else if(2*h <= s) cout << (n-1)*d/2 + 2*h;
        else cout << (n-1)*d/2 + s;
    }

    return 0;
}