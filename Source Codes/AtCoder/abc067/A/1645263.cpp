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

    int A, B;


    cin >> A >> B;


    int C=A+B;


    string Answer="Impossible";

    vector<int> array={A,B,C};//no zero

    for(const int value : array){

        if(value%3==0){

            Answer="Possible";
        }

    }




    cout  << Answer << endl ;

    return 0;
}