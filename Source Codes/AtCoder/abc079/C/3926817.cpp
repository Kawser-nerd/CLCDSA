#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bitset<3> b;
    int num = 0;
    string ans = "";
    for (int i=0; i<8; ++i){
        b = static_cast<bitset<3>>(i);
        num = s[0] - '0';
        for (int j=0; j<3; ++j){
            if(b[j] == 0){
                num += s[j+1] - '0';
            }
            else {
                num -= s[j+1] - '0';
            }
        }
        if(num == 7){
            ans += s[0];
            ans += (b[0]) ? "-" : "+";
            ans += s[1];
            ans += (b[1]) ? "-" : "+";
            ans += s[2];
            ans += (b[2]) ? "-" : "+";
            ans += s[3];
            ans += "=7";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}