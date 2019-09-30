#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    double x;
    double y;
    cin >> x >> y;

    int m;
    int n;

    m = y / x;

    n = static_cast<int>(m);

    cout << n << endl;

}