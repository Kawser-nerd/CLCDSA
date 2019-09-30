#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main(){

    int T, N, M, tmp;
    cin >> T;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < A.size(); ++i){
        cin >> tmp;
        A[i] = tmp;
    }
    
    cin >> M;
    vector<int> checked(M);
    vector<int> B(M);
    for(int i = 0; i < B.size(); ++i){
        cin >> tmp;
        B[i] = tmp;
        checked[i] = 0;
    }

    if(N < M){
        cout << "no" << endl;
        return 0;
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(A[i] > B[j] && checked[j] == 0){
                cout << "no" << endl;
                return 0;
            } 

            if( (abs(A[i]-B[j])<=T) && checked[j] == 0){
                checked[j] = 1;
                break;
            }
        }
    }

    if(count(checked.begin(), checked.end(),0)==0){
        cout << "yes" << endl;
        return 0;
    } 

    cout << "no" << endl;
    return 0;

}