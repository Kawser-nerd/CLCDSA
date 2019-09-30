#include<iostream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;
#define ll long long 

int  main(){
    int a,b;
    string s,t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    if(s < t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}