#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    string input[200];
    for (int i = 0; i < 2 * h; i+=2) {
        cin >> input[i];
        input[i+1] = input[i];
    }
    for (int i = 0; i < 2*h; i++) {
        cout << input[i] << endl;
    }
    return 0;
}