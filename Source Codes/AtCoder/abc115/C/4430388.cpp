#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n, k;
    int h[100005];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h, h+n);
    int diff_max = INT_MAX;
    for(int i = 0; i <= n-k; i++)
    {
        int diff = h[i+k-1] - h[i];
        if (diff_max > diff) diff_max = diff;
    }
    cout << diff_max << endl;
    return 0;
}