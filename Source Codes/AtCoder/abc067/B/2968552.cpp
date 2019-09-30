#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){

    int N, K;
    int total = 0;

    cin >> N >> K;
    vector<int> l(N);
    for(int i = 0; i < N; ++i){
        cin >> l[i];
    }

    sort(l.begin(), l.end(), greater<int>() );

    for(int i = 0; i < K; ++i){
        total += l[i];
    }
    cout << total << endl;
}