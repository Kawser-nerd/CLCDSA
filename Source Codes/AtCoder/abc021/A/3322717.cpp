#include<iostream>
#include <string>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    if (n == 1) a = 1, b = 0;
    else for (int i = 0;i < n; ++i){
            for (int j = 0;j < n; ++j){
                if (n == 1 * i + 2 * j) a = i, b = j;
        }
    }
    cout << a+b << endl;
    for (int i = 0; i < a; ++i) cout << 1 << endl;
    for (int j = 0; j < b; ++j) cout << 2 << endl;
}