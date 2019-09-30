#include<iostream>
#include<vector>

using namespace std;

void solve(int N, int M, vector<int> v){
    sort(v.begin(), v.end());
    for(int i = 0 ; i < M-1 ; i++){
        v[i] = v[i+1]-v[i];
    }
    v.pop_back();
    sort(v.begin(), v.end());
    int sum=0;
    for(int i = 0 ; i < (int)v.size()-N+1 ; i++){ // M-N = M-1-N+1
        sum += v[i];
    }
    cout << sum << endl;
    return;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> X(M);
    for(int i = 0 ; i <  M ; i++){
        cin >> X[i];
    }
    solve(N,M, move(X));
    return 0;
}