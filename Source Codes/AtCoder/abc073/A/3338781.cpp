#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string n;
    cin >> n;
    if(n[0] == '9') cout << "Yes" << endl;
    else if (n[1] == '9') cout << "Yes" << endl;
    else cout << "No" << endl;
}