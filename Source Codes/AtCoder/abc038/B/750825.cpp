#include <iostream>
        using namespace std;
        int main(void)
        {
            int h1, w1, h2, w2;
            cin >> h1;
            cin >> w1;
            cin >> h2;
            cin >> w2;
            if (h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return 0;
        }