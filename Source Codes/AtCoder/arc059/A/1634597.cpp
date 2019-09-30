//
// Created by Akifumi Ohata on 2017/09/29.
//

#include<iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>

using namespace std;

int main(){

    int N;



    cin >> N ;

    std::vector<int> arrays(static_cast<unsigned long>(N), 0);

    for(int i=0;i<N;i++){

        cin >> arrays[i];

    }

    int sum = std::accumulate(arrays.begin(), arrays.end(), 0);

    double div=N;
    int avarage= static_cast<int>(std::lround(sum/div));

    //cout << avarage<< endl;
    std::vector<int> cost_array;

    for(const int a : arrays){

        int dis=(a-avarage);
        cost_array.push_back(dis*dis);
    }

    int costsum = std::accumulate(cost_array.begin(), cost_array.end(), 0);

    cout << costsum <<endl;

    return 0;
}