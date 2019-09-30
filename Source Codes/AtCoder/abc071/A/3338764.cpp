#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    if(abs(a-x) > abs(b-x)) cout << "B" << endl;
    else cout << "A" << endl;
}