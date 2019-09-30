#include<iostream>
#include <string>
using namespace std;

int main(){
    int a;
    cin >> a;
    int x, y;
    if (a % 2 == 0)
    {
        x = a/2;
        y = a/2;
    }
    else{
        x = a/2;
        y = a/2 + 1;
    }
    cout << x * y << endl;
    return 0;
}