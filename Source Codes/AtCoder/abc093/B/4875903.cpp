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
    int a,b,k;
    cin >> a >> b >> k;
    for(int i=0; i<k; i++){
        if(a+i<=b){
            cout << a+i << endl;
        }
    }
    for(int i=0; i<k; i++){
        if(b-k+i+1>a+k-1 && b-k+i+1>=a){
            cout << b-k+i+1 << endl;
        }
    }


    return 0;
}