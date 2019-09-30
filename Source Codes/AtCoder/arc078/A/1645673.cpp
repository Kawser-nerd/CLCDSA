//
// Created by Akifumi Ohata on 2017/10/01.
//


#include<iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll =  long long int;

int main() {
    ios::sync_with_stdio(false);

    int N;

    ll MOD=1000000007;


    cin >> N ;




    vector<int> Array(N,0);

    ll value_A=0;
    for(int iter=0;iter<=N-1;iter++){
        cin >>Array[iter];
        value_A+=Array[iter];
    }

    ////
    ll value_S=0;
   // ll value_A=std::accumulate(Array.begin(), Array.end(), 0);

    ll Diff= 9223372036854775807LL;//;=1000000000000000000LL

    for(int k=0;k<=N-2;k++){


        value_S+=Array[k];
        value_A-=Array[k];



        Diff=min(Diff,abs(value_S-value_A));

    }











    cout  << Diff << endl ;

    return 0;
}