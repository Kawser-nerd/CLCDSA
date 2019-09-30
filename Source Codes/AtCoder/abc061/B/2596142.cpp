#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    cin>>n>>m;

    const int N = n+1;
    vector<int> city(N);
    int a, b;
    for (int i=0; i<m; ++i) {
        cin>>a>>b;
        city[a] += 1;
        city[b] += 1;
    }

    for (int i=1; i<N; ++i) {
        cout<<city[i]<<endl;
    }
    return 0;
}