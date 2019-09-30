#include <iostream>

using namespace std;

bool used[100000] = {false};

int main(){
    int cnt = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        if(!used[A])used[A] = true;
        else cnt++;
    }
    if(cnt%2 == 0) cout << N-cnt << endl;
    else cout << N-cnt-1 << endl;
}