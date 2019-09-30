#include <iostream>
#include <cmath>

using namespace std;

long long p10[19];

long long search(long long D, int len, bool first = false){
    if(abs(D) >= p10[len]) return 0;
    if(len <= 1) return D == 0 ? p10[len] : 0;
    long long res = 0;
    for(int dif=-9;dif<=9;dif++){
        long long add = dif * p10[len-1] - dif;
        long long newD = D + add;
        if(abs(newD) % 10 != 0) continue;
        long long mul = 10 - abs(dif) - (first && dif <= 0 ? 1 : 0);
        res += mul * search(newD/10, len-2);
    }
    return res;
}

int main(){
    p10[0] = 1;
    for(int i=1;i<19;i++) p10[i] = 10 * p10[i-1];
    long long D;
    while(cin >> D){
        long long res = 0;
        for(int i=1;i<=18;i++) res += search(D, i, true);
        cout << res << endl;
    }
}