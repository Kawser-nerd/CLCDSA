#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string x, y;
    cin >> x >>y;
    if (x < y) printf("<\n");
    else if (x == y) {
        printf("=\n");
    } else {
        printf(">\n");
    }
    return 0;
}