#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    if ((n/2) >= x) cout << x-1 << endl;
    else cout << n-x << endl;
}