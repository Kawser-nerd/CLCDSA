#include <iostream>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    int n = 0;
    
    for (int i=0; i<H; i++) {
        for (int j=1; j<W; j++) {
            n++;
        }
    }
    for (int i=0; i<W; i++) {
        for (int j=1; j<H; j++) {
            n++;
        }
    }
    
    cout << n << endl;
    return 0;
}