#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int

using namespace std;
int N,M;

int main(){
    cin >> N >> M;
    if(N >= M) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> X(M);
    vector<int> dis(M-1);
    for(int i= 0; i< M;i++){
        cin >> X[i];
    }
    sort(X.begin(),X.end());
    for(int i=0;i<M-1;i++){
        dis[i] = X[i+1] - X[i];
    }
    sort(dis.begin(),dis.end(),greater<int>());
    ll sum = 0;
    for(int i = 0; i< N-1; i++){
        sum += dis[i];
    }
    cout << X[X.size()-1] - X[0] - sum << endl;
    return 0;
}