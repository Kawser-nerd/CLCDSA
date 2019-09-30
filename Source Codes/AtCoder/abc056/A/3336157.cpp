#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    if (a == "H" && b== "D") cout << "D" << endl;
    else if (a == "H" && b== "H") cout << "H" << endl;
    else if (a == "D" && b== "D") cout << "H" << endl;
    else cout << "D" << endl;
}