#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    int sum;
    cin >> s;
    bitset<3> b;
    for(int i=0; i<8; ++i){
        // 0 -> +, 1 -> -
        b = static_cast<bitset<3>>(i);
        sum = s[0] - '0';
        for(int j=0; j<3; ++j){
            if(b[j] == 0){
                sum += s[j+1] - '0';
            }
            else {
                sum -= s[j+1] - '0';
            }
        }
        if(sum == 7){
            for(int j=0; j<=3; ++j){
                cout << s[j];
                if(j == 3){
                    cout << "=7" << endl;
                }
                else {
                    cout << ((b[j] == 0) ? '+' : '-');
                }
            }
            break;
        }
    }
}