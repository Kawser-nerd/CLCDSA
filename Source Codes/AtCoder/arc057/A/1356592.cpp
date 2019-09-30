#include <iostream>
using namespace std;
using ull = unsigned long long;
#define INF 2000000000000

int main(){
    ull A, K, ans = 0;
    cin >> A >> K;

    if(K == 0){
        cout << INF - A << endl;
    }else{
        while(A < INF){
            A += 1 + K*A;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;

}