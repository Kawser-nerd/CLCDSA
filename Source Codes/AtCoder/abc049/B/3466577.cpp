#include <iostream>
#include <string>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++ ) {
        string buf;
        cin >> buf;
        cout << buf << '\n' << buf << '\n';
    }
    return 0;
}