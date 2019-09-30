#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long 

int main(){
    int r,g,b;
    int N;
    cin >> N;
    LL ans = 0;
    vector <int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    cout << a[N-1] - a[0] << endl;
}