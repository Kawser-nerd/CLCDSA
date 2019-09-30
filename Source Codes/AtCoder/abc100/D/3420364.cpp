#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    long long answer, value, v_tmp;
    answer = 0;
    vector<long long> x, y, z;
    vector<long long> v;
    v.resize(8);
    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    for (int i=0; i<n; ++i){
        cin >> x[i] >> y[i] >> z[i];
    }
    v.resize(n);
    for (int k=0; k<8; ++k){
        value = 0;
        for (int i=0; i<n; ++i){
            switch(k){
            case 0:
                v_tmp = x[i] + y[i] + z[i];
                break;
            case 1:
                v_tmp = x[i] + y[i] - z[i];
                break;
            case 2:
                v_tmp = x[i] - y[i] + z[i];
                break;
            case 3:
                v_tmp = x[i] - y[i] - z[i];
                break;
            case 4:
                v_tmp = (-1 * x[i]) + y[i] + z[i];
                break;
            case 5:
                v_tmp = (-1 * x[i]) + y[i] - z[i];
                break;
            case 6:
                v_tmp = (-1 * x[i]) - y[i] + z[i];
                break;
            case 7:
                v_tmp = (-1 * x[i]) - y[i] - z[i];
                break;
            }
            v[i] = v_tmp;
            //cout << v_tmp << endl;
        }
        sort(v.begin(), v.end(), std::greater<long long>());
        for (int j=0; j<m; ++j){
            value += v[j];
        }
        answer = max(answer, abs(value));
    }
    cout << answer << endl;
}