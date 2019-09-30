#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int  main(){
    string S;
    int a,b;
    int tmp;
    cin >> S;
    cout << "2018" + S.substr(4,S.size()-4) << endl;
}