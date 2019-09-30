#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    long A[100000];
    long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    for(int i = 0; i < N; i++){
        sum += A[i];
    }
    for(int i = N-1; i >= 0; i--){
        sum -= A[i];
        if(2*sum < A[i]){
            cout << N-i << endl;
            break;
        }
    }
}