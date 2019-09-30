#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < N; ++i){
       if(s[i] == '+')ans++;
       else ans--;
    }

    cout << ans / K << endl;

    return 0;
        
}