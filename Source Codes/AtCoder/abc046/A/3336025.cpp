#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, variance=3;
    cin >> a >> b >> c;
    if(a==c) variance--;
    else if(a==b) variance--;
    else if(b==c) variance--;
    if(a==b && b==c) variance--;
    cout << variance << endl;
}