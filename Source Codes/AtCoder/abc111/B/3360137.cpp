#include <iostream>
using namespace std;
//using ll=long long;

int main(){
    int N;
    cin >> N;
    int res = N;
    for(res = N; res <= 999; res++){
        if(res % 111 == 0) break;
    }
    cout << res << endl;
    
    return 0;
}