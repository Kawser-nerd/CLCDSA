#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    double ans = 0.0;
    double d;
    for (int i=0; i<n; ++i){
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            ans = max(ans, d);
        }
    }
    printf("%.8f\n", ans);
}