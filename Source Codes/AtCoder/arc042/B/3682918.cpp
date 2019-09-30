#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    double sx, sy, min, l, tmp;
    int n, a, b, c, d;
    const double INF = 100000.0;
    cin >> sx >> sy >> n;
    vector<double> x(n);
    vector<double> y(n);
    min = INF;
    for(int i=0; i<n; ++i){
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<n; ++i){
        a = x[i] - sx;
        b = y[i] - sy;
        c = (i == n-1) ? (x[0] - sx) : (x[i+1] - sx);
        d = (i == n-1) ? (y[0] - sy) : (y[i+1] - sy);
        l = sqrt((double)pow(c-a, 2) + (double)pow(d-b, 2));
        tmp = fabs(a * d - b * c) / l;
        min = fmin(min, tmp);
    }
    printf("%.10f", min);
    cout << endl;
}