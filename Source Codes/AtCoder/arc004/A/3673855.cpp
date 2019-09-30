#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double x, y, ans, d;
    ans = 0.0;
    vector<pair<int, int>> p;
    for(int i=0; i<n; ++i){
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            d = sqrt(pow(fabs((double)p[j].first - (double)p[i].first), 2) + pow(fabs((double)p[j].second - (double)p[i].second), 2));
            if(d > ans){
                ans = d;
            }
        }
    }
    printf("%.6f", ans);
    cout << endl;
    return 0;
}