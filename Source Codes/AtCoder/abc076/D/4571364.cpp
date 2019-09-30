#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    int N;
    cin >> N;
    int tl[N + 2], tr[N + 2], v[N + 2];
    tl[0] = 0;
    tr[0] = 0;
    int endt = 0;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        tl[i] = tr[i - 1];
        tr[i] = tl[i] + tmp;
        endt += tmp;
    }
    tl[N + 1] = tr[N];
    tr[N + 1] = tl[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    v[0] = 0;
    v[N + 1] = 0;

    double spd[2 * endt + 1];
    for (int i = 0; i <= 2 * endt; i++) {
        spd[i] = 1000000000;
        for (int j = 0; j < N + 2; j++) {
            double tmp;
            double tnow = double(i) / 2;
            //cout << "tnow" << tnow << endl;
            //cout << tl[j] << tr[j] << endl;
            if (tnow < tl[j]) {
                tmp = v[j] + tl[j] - tnow;
            } else if (tr[j] < tnow) {
                tmp = v[j] + tnow - tr[j];
            } else if (tl[j] <= tnow && tnow <= tr[j]) {
                tmp = v[j];
            }
            spd[i] = min(spd[i], tmp);
        }
        //cout << "i=" << i << " " << spd[i] << endl;
    }

    /*for(int i=0;i<N+2;i++){
      cout << tl[i] << " " << tr[i] << " " << v[i] << endl;
    }*/

    double sum = 0;
    for (int i = 1; i <= 2 * endt; i++) {
        sum += (spd[i] + spd[i - 1]) * 0.5 / 2;
    }

    //printf("%.15lf\n", sum);
    cout << fixed << setprecision(12) << sum << "\n";
    return 0;
}