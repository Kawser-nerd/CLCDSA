#include <iostream>
#include <vector>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X;
    vector<int> A;
    cin >> N >> M >> X;
    A.resize(M, 0);
    for(int i = 0; i < M; ++i){
        cin >> A[i];
    }

    int rightPath = 0, leftPath = 0;
    for(int i = X; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(i == A[j]){
                rightPath++;
            }
        }
    }
    for(int i = X; i > 0; --i){
        for(int j = 0; j < M; ++j){
            if(i == A[j]){
                leftPath++;
            }
        }
    }

    if(rightPath <= leftPath){
        cout << rightPath << "\n";
    }
    else{
        cout << leftPath << "\n";
    }

    return 0;
}