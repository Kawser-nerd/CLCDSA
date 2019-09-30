#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
//Boost C++ Libraries
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace ublas = boost::numeric::ublas;
*/

int main(void){
    //
    string w;
    cin >> w;

    vector<int> arr(26);

    for(int i=0;i<w.length();i++){
        arr[ w.at(i) -'a'] += 1;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]%2==1){
            cout << "No" << endl;
            return 0;
            break;
            
        }
    }
    cout << "Yes" << endl;
    return 0;
}