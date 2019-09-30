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
    vector<int> towers;
    towers.push_back(0);
    for(int i=1; i<1000; i++){
        towers.push_back(towers[i-1]+i);
    }
    int d=b-a;
    cout << towers[d-1]-a;
    

    return 0;
}