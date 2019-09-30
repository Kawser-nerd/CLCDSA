#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, ab, ac, bc;
    cin >> a >> b >> c;
    ab = a+b;
    ac = a+c;
    bc = b+c;
    int min = ab;
    if(ac <= min)
        min = ac;
    if(bc <= min)
        min = bc;
    cout << min << endl;
}