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
    int ans;
    ans=max(a+b, a-b);
    ans=max(ans, a*b);
    cout << ans;
    return 0;
}