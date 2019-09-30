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
    char s[3][4];
    for(int i=0; i<3; i++){
        cin >> s[i];
    }
    cout << s[0][0] << s[1][1] << s[2][2];
    
    return 0;
}