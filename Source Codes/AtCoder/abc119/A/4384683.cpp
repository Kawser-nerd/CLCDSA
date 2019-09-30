//
// Created by Suganami Shuya on 2019-02-25.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string token, p = "2019/04/30";
    cin >> token;

    if (token <= p) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }

    return 0;
}