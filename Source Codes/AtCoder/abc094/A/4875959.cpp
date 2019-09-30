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
    int a,b,x;
    cin >> a >> b >> x;
    if(x>=a && x<=a+b){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}