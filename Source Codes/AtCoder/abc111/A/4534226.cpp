#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    string n;
    cin >> n;
    for(int i = 0;i<3;i++){
        if(n[i] == '1'){
            n[i] = '9';
        }
        else{
            n[i] = '1';
        }
    }
    for(int i = 0;i<3;i++){
        cout << n[i];
    }
    cout << endl;
}