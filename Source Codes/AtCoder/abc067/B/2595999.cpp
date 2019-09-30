#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k, l;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (int i=0; i<k; ++i) {
        sum += v[i];
    }
    cout<<sum<<endl;
    return 0;
}