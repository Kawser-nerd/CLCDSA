//
// Created by Akifumi Ohata on 2017/09/30.
//


#include<iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>
#include<string>

using namespace std;

using ll =  long long int;

int main() {

    string S;


    cin >> S;

    unsigned long size_S = static_cast<int>(S.size());

    for(int iter=1;iter <=size_S;iter++){

        //S.erase(size_S-1);

        if((size_S -iter) %2 !=0) {
            continue;
        }else {

            unsigned long mid = ((size_S-iter) / 2);

            string part1;
            part1 = S.substr(0, mid-1 );

            string part2;
            part2 = S.substr(mid, mid-1 );

           // cout << part1 << " " << part2 << endl;

            if (part1 == part2) {

                cout <<  size_S - iter << endl;
                return 0;
            }
        }
    }

}