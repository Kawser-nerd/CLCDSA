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
    int N,X;
    cin >> N >> X;
    vector<int> donut(N);
    for(int i=0; i<N; i++){
        cin >> donut[i];
        X-=donut[i];
    }
    sort(donut.begin(), donut.end());
    cout << N+X/donut[0];

    return 0;
}