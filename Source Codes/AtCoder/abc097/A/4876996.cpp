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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}