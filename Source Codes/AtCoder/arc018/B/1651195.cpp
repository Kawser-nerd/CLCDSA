//
// Created by Akifumi Ohata on 2017/10/04.
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

    ///read
    cin >> N ;

    pair<int,int> ini = make_pair(0,0);
    vector<pair<int,int>> points(N,ini);


    for(int i=0;i<N;i++){

        cin >> points[i].first >> points[i].second;
    }


    /// combination
    int n = N;
    int r = 3;
    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);
    std::vector<std::vector<int>> Ans;

    do {

        std::vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                tmp.push_back(i+1);
                // std::cout << (i + 1) << " ";
            }
        }
        Ans.push_back(tmp);
        // std::cout << "\n";
    } while (std::next_permutation(v.begin(), v.end()));


    int counter=0;
    for(const auto &tri : Ans){

        pair<ll,ll> a,b,c;

        a=points[tri[0] -1];
        b=points[tri[1] -1];
        c=points[tri[2] -1];

        ll S =((abs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first))));

        if(S!=0 && S%2==0 ) {
            //cout << S << endl;
            counter++;
        }
    }



    cout  << counter << endl ;

    return 0;
}