#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int ab, bc, ca;
    cin >> ab >> bc >> ca;

    float s = (ab + bc + ca) / 2;
    int result = sqrt(s * (s - ab) * (s - bc) * (s - ca));
    cout << result << endl;
}