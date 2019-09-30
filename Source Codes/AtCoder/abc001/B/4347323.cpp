#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int m;
    int p[2];
    int q;
    cin >> m;
    if(m < 100){
        p[0] = 0;
        p[1] = 0;
    }
    else if(100 <= m && m < 1000){
        q = m / 100;
        p[0] = 0;
        p[1] = q;
    }
    else if (1000 <= m && m <= 5000){
        p[0] = m / 1000;
        p[1] = (m/100) % 10;
    }
    else if (6000 <= m && m <= 30000){
        p[0] = (m / 10000) + 5;
        p[1] = (m / 1000) % 10;
    }
    else if (35000 <= m && m <= 70000){
        q = (m / 1000);
        q = ((q -30) / 5);
        p[0] = ((q / 10) + 8);
        p[1] = (q % 10);
    }
    else{
        p[0] = 8;
        p[1] = 9;
    }
    cout << p[0] << p[1] << endl;
}