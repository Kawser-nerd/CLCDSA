#include <iostream>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int num[N + 1];
    for(int i = 0; i < N+1; ++i){
        num[i] = 0;
    }

    int L[Q], R[Q];
    for(int i = 0; i < Q; ++i){
        cin >> L[i] >> R[i];
    }
    
    for(int i = 0; i < Q; ++i){
        num[L[i]-1]++;
        num[R[i]]--;
    }
    for(int i = 0; i < N; i++){
        num[i+1] = num[i] + num[i+1];
        cout << (num[i] & 1);
    }
    cout << endl;

    return 0;
}