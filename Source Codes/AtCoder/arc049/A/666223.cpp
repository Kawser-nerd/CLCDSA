#include <stdio.h>
#include <iostream>

using namespace std;

#define string(x) string x; cin >> x;

int main (int argc, char *argv[]) {
    string(x);
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    int c = 0;

    for(int i = 0; i < (int)x.size(); i++) {
        if (i == a[0] || i == a[1] || i == a[2] || i == a[3]) {
            std::cout << "\"";
            c++;
        }
        std::cout << x[i];
    }
    if (c == 3) cout << "\"";
    std::cout << endl;
}