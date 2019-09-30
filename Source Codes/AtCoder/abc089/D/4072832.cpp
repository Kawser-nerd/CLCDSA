#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    int as[h*w+1][2];
    int r[h*w+1];
    int a;
    as[0][0] = 0;
    as[0][1] = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a;
            as[a][0] = i;
            as[a][1] = j;
        }
    }
    for(int i = 0; i < d; i++){
        r[i] = 0;
    }
    for(int i = d+1; i <= h*w; i++){
        r[i] = r[i-d]+(abs(as[i-d][0]-as[i][0])+abs(as[i-d][1]-as[i][1]));
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int L,R;
        cin >> L >> R;
        cout << r[R]-r[L] << endl;
    }
    
    return 0;
}