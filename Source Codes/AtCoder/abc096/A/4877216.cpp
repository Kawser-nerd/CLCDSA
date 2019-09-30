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
    int a,b;
    cin >> a >> b;
    if(a<=b){
        a++;
    }
    cout << a-1;
    return 0;
}