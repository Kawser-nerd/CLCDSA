#include<iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    if (n[0]==n[1] && n[0] == n[2] && n[0] == n[3]){
        cout << "SAME" << endl;
    }
    else {
        cout << "DIFFERENT" << endl;
    }
}