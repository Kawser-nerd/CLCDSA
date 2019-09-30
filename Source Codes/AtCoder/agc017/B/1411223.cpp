#include <iostream>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>
#include <math.h>
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <vector>
using namespace std;

int n,a,b,c,d,e;

int main(){
    cin >> n >> a >> b >> c >> d;
    long long i, j, k;
    long long dist = b - a;
    long long minp, maxp, minn, maxn;
    minp = b + c - a; maxp = b + d - a; minn = b - d - a; maxn = b - c - a;
    //cout << minp << " " << maxp << " " << minn << " " << maxn << "\n";
    for(i = 0; i <= n - 2; i++){
        long long mini,maxi;
        mini = i * c - (n - 2 - i) * d;
        maxi = i * d - (n - 2 - i) * c;
        //cout << i << " " << mini << " " << maxi <<"\n";
        if(minp <= maxi && maxp >= mini){
            cout << "YES" << "\n";
            return 0;
        }
        else if(minn <= maxi && maxn >= mini){
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;

}