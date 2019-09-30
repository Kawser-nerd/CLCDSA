#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a*b % 2 == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}