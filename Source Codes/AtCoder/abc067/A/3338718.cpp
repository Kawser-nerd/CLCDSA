#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a%3 == 0) cout << "Possible" << endl;
    else if(b%3 == 0) cout << "Possible" << endl;
    else if((a+b)%3 == 0) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}