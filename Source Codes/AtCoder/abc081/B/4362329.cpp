#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
     vector<int>A(N);
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        int tmp = 0;
        while(A[i] % 2 == 0){
            A[i] /= 2;
            tmp++;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}