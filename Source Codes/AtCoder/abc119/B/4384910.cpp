//
// Created by Suganami Shuya on 2019-02-25.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    double money, total = 0.0, oneBit = 380000.0;
    string moneyType;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> money >> moneyType;
        if (moneyType == "JPY") {
            total += money;
        } else {
            total += money * oneBit;
        }
    }
    cout << total << endl;
    return 0;
}