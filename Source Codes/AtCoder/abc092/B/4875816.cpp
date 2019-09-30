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
    int N,D,X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int ans=0;
    for(int i=0; i<N; i++){
        ans+=(D-1)/A[i]+1;
    }
    cout << ans+X;


    return 0;
}