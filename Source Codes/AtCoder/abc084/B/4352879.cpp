#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int  main(){
    int A, B;
    string S;
    int a,b;
    int tmp = 1e9, ans = 0;
    bool flag = true;
    cin >> A >> B;
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(i == A){
            if(S[i] != '-')flag = false;
        }else{
            if(S[i] == '-')flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}