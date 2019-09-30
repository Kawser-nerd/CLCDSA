#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long count = 0;
    int buf = 0;
    bool findB = false;
    for(int i = 0; i < s.size(); i++){
        if(!findB){
            if(s[i] == 'B'){
                findB = true;
            }else{
                buf++;
            }
            continue;
        }
        if(s[i] == 'W'){
            count += (i-buf);
            buf++;
        }
    }
    cout << count << endl;
    return 0;
}