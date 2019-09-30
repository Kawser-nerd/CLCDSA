#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int d = max(max(a,b),c);
    cout << 9*d + a + b + c << endl;
}