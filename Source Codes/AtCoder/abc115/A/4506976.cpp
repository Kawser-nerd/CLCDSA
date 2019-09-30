#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int d;
    cin >> d;
    string a;
    if(d == 25){
        a = "Christmas";
    }
    else if(d == 24){
        a = "Christmas Eve";
    }
    else if(d == 23){
        a = "Christmas Eve Eve";
    }
    else{
        a = "Christmas Eve Eve Eve";
    }
    cout << a << endl;
}