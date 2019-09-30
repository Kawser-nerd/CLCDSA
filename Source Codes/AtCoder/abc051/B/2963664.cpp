#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){

    int K, S;
    int x, y, z;
    int ans = 0;

    cin >> K >> S;

    for(x = 0; x <= K; ++x){
        for(y = 0; y <= K; ++y){
            z = S - x -y;
            if( 0 <= z && z <= K ){
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}