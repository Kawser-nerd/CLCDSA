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
    if(s[0]!=s[1] && s[0]!=s[2] && s[1]!=s[2]){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}