#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> x(3);
    vector<double> y(3);
    double s;
    for(int i=0; i<3; ++i){
        cin >> x[i] >> y[i];
    }
    x[2] -= x[0];
    y[2] -= y[0];
    x[1] -= x[0];
    y[1] -= y[0];
    x[0] = 0;
    y[0] = 0;
    s = fabs(x[1] * y[2] - y[1] * x[2]) / 2.0;
    printf("%.5f", s);
    cout << endl;
}