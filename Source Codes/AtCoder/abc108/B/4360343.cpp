#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int x_1,x_2,y_1,y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    int dx,dy;
    dx = x_2 - x_1;
    dy = y_2 - y_1;
    cout << x_2  - dy << " " << y_2 + dx  << " " << x_1 - dy << " " << y_1 + dx << endl; 
}