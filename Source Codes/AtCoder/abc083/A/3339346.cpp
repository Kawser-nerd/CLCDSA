#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int l=a+b, r=c+d;
    if(l>r) cout << "Left" << endl;
    else if(l<r) cout << "Right" << endl;
    else cout << "Balanced" << endl;
}