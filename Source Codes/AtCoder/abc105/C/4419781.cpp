#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,tmp,n,m;
    string s = "";
    cin >> N;

    while(N != 0){
        tmp = N % 2;
        if(tmp < 0) tmp = 1;
        N = (N - tmp) / -2;
        s += (char)(tmp + '0');
    }
    reverse(s.begin(), s.end());
    if(s == "") s = "0";
    cout << s << endl;
    
}