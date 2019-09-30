//
// Created by Akifumi Ohata on 2017/09/30.
//


#include<iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>

using namespace std;

using ll =  long long ;

int main() {

    int A, B,C;

    cin >> A >> B >> C;


    std::vector<int> array(3,0);


    array[0]=A+B;
    array[1]=B+C;
    array[2]=C+A;


    std::vector<int>::iterator iter = std::min_element(array.begin(), array.end());
    size_t index = static_cast<size_t>(std::distance(array.begin(), iter));

    cout<< array[index] << endl;

    return 0;

}