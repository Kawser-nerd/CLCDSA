#include<iostream>
using namespace std;

int main() {
    int w,h;
    cin >> w >> h;
    char c;
    int cnt = 0;
    while(cin >> c) if (c == '#') cnt++;
    if (cnt == w + h - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}