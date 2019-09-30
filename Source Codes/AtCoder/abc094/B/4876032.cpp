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
    int N,M,X;
    cin >> N >> M >> X;
    int left=0,right=0;
    for(int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        if(tmp<X) left++;
        else right++;
    }
    cout << min(right, left);


    return 0;
}