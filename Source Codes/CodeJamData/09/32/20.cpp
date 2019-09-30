#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

string calc() {
    int N;
    cin >> N;
    double d[3];
    double v[3];
    for (int i = 0; i < 3; i++) d[i] = v[i] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            double a;
            cin >> a;
            d[j] += a;
        }
        for (int j = 0; j < 3; j++) {
            double a;
            cin >> a;
            v[j] += a;
        }    
    }
    for (int i = 0; i < 3; i++) {
        d[i] /= N;
        v[i] /= N;
    }
    double dNum = d[0] * v[0] + d[1] * v[1] + d[2] * v[2];
    double dDen = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    
    double dTime = 0;
    if (fabs(dDen) > 1e-9) {
       dTime = - dNum / dDen;
    }
    if (dTime < 0) dTime = 0;
    
    
    double dDist = 0;
    for (int i = 0; i < 3; i++) {
        dDist += pow(d[i] + v[i] * dTime, 2);    
    }
    dDist = sqrt(dDist);
       
    stringstream oss;
    oss.setf(ios::fixed);
    oss.precision(8);
    oss << dDist << " " << dTime;
    return oss.str();
}

int main() {
    int T;
    cin >> T >> ws;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << calc() << endl;
    }
}
