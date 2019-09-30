#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int x = stoi(a+b);
    for (int i = 1; i <= int(sqrt(float(x))); i++) { 
        if (x / i == i && x % i == 0) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}