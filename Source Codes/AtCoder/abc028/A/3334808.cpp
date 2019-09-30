#include<iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n <= 59) cout << "Bad" << endl;
    else if (n >= 60 && n <= 89) cout << "Good" << endl;
    else if (n >= 90 && n <= 99) cout << "Great" << endl;
    else cout << "Perfect" << endl;
    return 0;
}