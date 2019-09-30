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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dis[2]={ty-sy, tx-sx};
    string d="URDL";
    for(int i=0; i<4; i++){
        for(int j=0; j<dis[i%2]; j++){
            cout << d[i];
        }
    }
    cout << 'L';
    for(int i=0; i<2; i++){
        for(int j=0; j<dis[i%2]+1; j++){
            cout << d[i];
        }
    }
    cout << "DR";
    for(int i=0; i<2; i++){
        for(int j=0; j<dis[i%2]+1; j++){
            cout << d[i+2];
        }
    }
    cout <<"U";
    return 0;
}