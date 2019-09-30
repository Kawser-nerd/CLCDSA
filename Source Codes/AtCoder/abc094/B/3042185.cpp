#include <iostream>
using namespace std;

int main() {
    int N, M, X;
    int A[100];

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++){
        cin >> A[i];
    }

    int l = 0;
    int r = 0;

    for (int i = 0; i < M; i++){
        if (A[i] < X) {
            l++;
        } else {
            r++;
        }
    }

    if (r > l){
        cout << l << endl;
    } else{
        cout << r << endl;
    }
    
    return 0;
}