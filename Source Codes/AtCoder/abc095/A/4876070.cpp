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
    string s;
    cin >> s;
    int ans=700;
    for(int i=0; i<3; i++){
        if(s[i]=='o') ans+=100;
    }
    cout << ans;
    return 0;
}