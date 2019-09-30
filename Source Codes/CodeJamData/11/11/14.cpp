//#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define Eo(x) {cerr<< #x << " = " << (x) << endl;}

typedef double real;
typedef long long int64;
const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-6;
typedef pair<int,int> pip;

int64 gcd(int64 a, int64 b){
    return a ? gcd(b%a,a) : b;
}

int main(){
    int T; cin >> T;
    for (int _ = 0;_<T;_++){
        printf("Case #%d: ",_+1);
        int64 n,pd,pg; cin >> n >> pd >> pg;
        int64 gg = 100/gcd(pd,100);
        bool good = true;
        do{
            if (gg>n){
                good = false;
                break;
            }
            if (pg == 100 && pd < 100) {
                good = false;
                break;
            }
            if (pg == 0 && pd > 0) {
                good = false;
                break;
            }
        }while(false);
        puts(good?"Possible":"Broken");
    }
    return 0;
}
