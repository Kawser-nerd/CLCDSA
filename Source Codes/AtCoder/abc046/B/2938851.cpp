#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int N,K;
    int ans;
    cin >> N >> K;
    ans = K;
    if(N > 1){
        for(int i = 2; i <= N; i++){
            ans *= (K-1);
        }
    }
    

    cout << ans << endl;


}