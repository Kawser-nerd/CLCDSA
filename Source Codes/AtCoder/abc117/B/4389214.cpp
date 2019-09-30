#include<iostream>
#include<vector>

using namespace std;

//?????????????????????????Yes???????No
void solve(int N, vector<int> v){
    sort(v.begin(), v.end());

    int sum = 0;
    for(int i=0; i<(int)v.size()-1; i++){
        sum += v[i];
    }
    if(sum > v[N-1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N ; i++){
        cin >> v[i];
    }
    solve(N, move(v));
    return 0;
}