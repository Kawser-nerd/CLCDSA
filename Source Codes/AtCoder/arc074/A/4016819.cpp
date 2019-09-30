#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)

int main(){
    long long int h,w; cin >> h >> w;
    long long int mul = (long long) h * w;
    if((mul % 3) == 0){cout << 0 << endl; return 0;}
    long long int ans = 10000000000;
    for(int i=1;i<h;i++){
        long long a = i * w;
        long long int hh = h - i;
        long long b = w*(hh/2);
        long long t = max(abs(a - b), (long long)w*(hh%2));
        t = max(abs(a - (mul - a - b)), t);
        ans = min(ans,  t);
        b = (w/2)*hh;
        t = max(abs(a - b), (long long)hh*(w%2));
        t = max(abs(a - (mul - a - b)), t);
        ans = min(ans,t);
    }
    swap(h,w);
    for(int i=1;i<h;i++){
        long long a = i * w;
        long long hh = h - i;
        long long b = w*(hh/2);
        long long t = max(abs(a - b), (long long)w*(hh%2));
        t = max(abs(a - (mul - a - b)), t);
        ans = min(ans,  t);
        b = (w/2)*hh;
        t = max(abs(a - b), (long long)hh*(w%2));
        t = max(abs(a - (mul - a - b)), t);
        ans = min(ans,t);
    }
    cout << ans << endl;
    return 0;
}