#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s; 
    int k;
    k = abs(100*(s[0] - '0') + 10 * (s[1] - '0') + (s[2] - '0') -753) ;
    int n;
    int size = s.size();
    for (int i = 0;i < size - 2;i++){
        n = abs((100 * (s[i] - '0') + 10 * (s[i+1] - '0') + (s[i+2] - '0') - 753));
        k = min(k,n);
    }
    cout << k << endl;
}