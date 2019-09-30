#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int k;
    cin >> k;
    if(k%2 == 1){
        cout << (k+1)*(k-1)/4 << endl;
    }
    else{
        cout << k*k/4 << endl;
    }
}