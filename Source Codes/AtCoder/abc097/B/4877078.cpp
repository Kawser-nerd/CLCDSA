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
    int x;
    cin >> x;
    vector<int> ans;
    ans.push_back(1);
    int b=2;
    while(b*b<=x){
        int tmp=b*b;
        ans.push_back(tmp);
        while(tmp*b<=x){
            tmp*=b;
        }
        ans.push_back(tmp);
        b++;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans[0];

    return 0;
}