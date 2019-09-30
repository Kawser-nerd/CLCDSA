#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a;
    cin >> a;
    int p = 0;
    for (int i = 0;i < 3;i++){
        if (a[i] == '1'){
            p = p + 1;
        }
    }
    cout << p << endl;
}