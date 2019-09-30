#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string n;
    int res=0;
    cin >> n;
    for(int i=0; i<3; ++i){
        if(n[i] == n[2-i]){
            res ++;
        }
    }
    if(res == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}