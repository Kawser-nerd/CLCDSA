#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    int tempMaximumT = INT_MIN;
    int maximumT = INT_MIN;
    for(int i = 0; i < N; ++i){
        int maximumA = INT_MIN;
        for(int j = 0; j < N; ++j){
            if(j != i){
                int tempSumA = 0;
                int tempSumT = 0;
                int p = max(i, j);
                int q = min(i, j);
                for(int k = q; k <= p; ++k){
                    if((k - q) % 2 == 1) tempSumA += A[k];
                    else tempSumT += A[k];
                }
                if(maximumA < tempSumA){
                    maximumA = tempSumA;
                    tempMaximumT = tempSumT;
                }
            }
        }
        
        if(maximumT < tempMaximumT){
            maximumT = tempMaximumT;
        }
    }

    cout << maximumT << endl;

    return 0;
}