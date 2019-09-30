#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    int a = 3;
    int b = 3;
    int c = 3;
    if(B <= A) a--;
    if(C <= A) a--;
    if(A <= B) b--;
    if(C <= B) b--;
    if(A <= C) c--;
    if(B <= C) c--;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}