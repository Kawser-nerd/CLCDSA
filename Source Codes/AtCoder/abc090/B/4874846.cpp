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
    int a, b;
    cin >> a >> b;
    int ans=0;
    for(int i=a; i<=b; i++){
        string s;
        s=to_string(i);
        if(s[0]==s[4] && s[1]==s[3]) ans++;
    }
    cout << ans;

    return 0;
}