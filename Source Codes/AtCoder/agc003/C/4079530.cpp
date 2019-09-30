#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main(){
    int N;
    int ans = 0;
    P A[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        A[i] = P(a, i);
    }
    sort(A, A+N);
    for(int i = 0; i < N; i++){
        if(i%2 != A[i].second%2) ans++;
    }
    cout << ans/2 << endl;
}