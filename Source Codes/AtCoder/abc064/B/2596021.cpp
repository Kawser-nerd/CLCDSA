#include <iostream>

using namespace std;

int main(void) {
    int n, a;
    cin>>n;
    int max_n = 0;
    int min_n = 1000;
    for (int i=0; i<n; ++i) {
        cin>>a;
        max_n = max(a, max_n);
        min_n = min(a, min_n);
    }
    cout<<(max_n-min_n)<<endl;
    return 0;
}