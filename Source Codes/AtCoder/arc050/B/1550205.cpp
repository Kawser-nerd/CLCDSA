#include <iostream>
using namespace std;

long long R, B, x, y;

bool C(long long mid){
    if(R < mid || B < mid) return false;
    long long tmp1 = (R-mid)/(x-1);
    long long tmp2 = (B-mid)/(y-1);
    return tmp1 + tmp2 >= mid;
}

int main(){
    cin >> R >> B >> x >> y;
    long long ub = max(R, B);
    long long lb = 0;
    while(ub - lb > 1){
        long long mid = (ub - lb) / 2 + lb;
        if(C(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
    return 0;
}