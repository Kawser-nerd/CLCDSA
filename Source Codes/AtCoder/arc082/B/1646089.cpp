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


    int tim=0;
    std::vector<int> Array;

    for(int i=1;i<=N;i++){

        int tmp;
        cin >>tmp;

        if(tmp==i){
            tim++;

        }else {
            Array.push_back(tim);
            tim = 0;
        }


        if(i==N && tim>0){
            Array.push_back(tim);
        }

    }


    int sum=0;
    for(const int time : Array){

        sum+=(time+1)/2;

    }


    cout  << sum << endl ;

    return 0;
}