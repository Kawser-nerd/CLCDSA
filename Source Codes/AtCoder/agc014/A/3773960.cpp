#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a, b, c, ha, hb, hc;
    cin >> a >> b >> c;
    int ans = -1;
    for (int i = 0; i < 100; ++i){
        if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
            ans = i;
            break;
        }
        else {
            ha = a / 2;
            hb = b / 2;
            hc = c / 2;
            a = hb + hc;
            b = hc + ha;
            c = ha + hb;
        }
        if(a == b && b == c){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}