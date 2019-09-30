#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a = min(a,b);
    c = min(c,d);
    cout << a+c;
    return 0;
}