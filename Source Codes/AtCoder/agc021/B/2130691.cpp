#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
using P = pair<int, int>;

int N;
vector<P> v;

double clip(double deg) {
    if (deg < 0) deg += 360;
    if (deg >= 360) deg -= 360;
    return deg;
}

bool inside(double mn, double mx, double deg) {
    if (mn <= mx) {
        return mn <= deg && deg <= mx;
    } else {
        return mn <= deg || deg <= mx;
    }
}

double width(double mn, double mx) {
    if (mn <= mx) return mx - mn;
    else return mx - mn + 360;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; ++i) {
        int xi = v[i].first;
        int yi = v[i].second;
        double mintheta = 0;
        double maxtheta = 360;
        bool first = true;
        bool close = false;
        //cout << "vert " << i << " (" << xi << ", " << yi << ")" << endl;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int xj = v[j].first;
            int yj = v[j].second;
            //cout << "   vert " << j << " (" << xj << ", " << yj << ")" << endl;

            int dx = xj - xi;
            int dy = yj - yi;
            double theta = atan2((double)dy, (double)dx) * 360 / (2 * M_PI);
            double mnt = clip(theta + 90);
            double mxt = clip(theta + 270);

            if (first) {
                mintheta = mnt;
                maxtheta = mxt;
                first = false;
            } else {
                close = true;
                if (inside(mintheta, maxtheta, mnt)) {
                    mintheta = mnt;
                    close = false;
                }
                
                if (inside(mintheta, maxtheta, mxt)) {
                    maxtheta = mxt;
                    close = false;
                }
                if (close) {
                    if (inside(mnt, mxt, mintheta) || inside(mnt, mxt, maxtheta)) close = false;
                }
            }

            //cout << "    min " << mintheta << " max " << maxtheta << endl;
            if (close) break;
        }
        double prob = 0;
        if (close) {
            //cout << "closed" << endl;
        } else {
            prob = width(mintheta, maxtheta) / 360;
            //cout << "min " << mintheta << " max " << maxtheta << endl;
        }
        printf("%.20f\n", prob);
    } 
}