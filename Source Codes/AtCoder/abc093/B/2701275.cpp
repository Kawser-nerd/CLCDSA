#include <iostream>
#include <vector>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, K;
    cin >> A >> B >> K;
    int range = B - A;
    vector<int> ans;

    if(range >= 2 * K){
        for(int i = A; i < A + K; i++){
            ans.push_back(i);
        }
        for(int i = B - K + 1; i <= B; i++){
            ans.push_back(i);
        }
    }
    else if(range <= K){
        for(int i = A; i <= B; i++){
            ans.push_back(i);
        }
    }
    else{
        for(int i = A; i < A + K; i++){
            ans.push_back(i);
        }
        for(int i = A + K; i <= B; i++){
            ans.push_back(i);
        }
    }

    for(int i : ans){
        cout << i << "\n";
    }

    return 0;
}