#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    string s;
    long long k;
    int p = 0;
    cin >> s;
    cin >> k;
    for(int i = 0;i<s.size();i++){
        if(s[i] != '1'){
            p = i+1;
            break;
        }
    }
    int ans;
    if(p == 0){
        ans = 1;
    }
    else if (k < p){
        ans = 1;
    }
    else{
        ans = s[p - 1] - '0';
    }
    cout << ans << endl;

}