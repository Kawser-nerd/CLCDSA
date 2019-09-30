#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, max;
    cin >> a >> b;
    max = a + b;
    if(a-b > max) max = a-b;
    if(a*b > max) max = a*b;
    cout << max << endl;
}