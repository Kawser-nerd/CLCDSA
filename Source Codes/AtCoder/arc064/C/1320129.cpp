#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <cstring>
#define MAX_N 1002
using namespace std;
int N;
double x[MAX_N];
double y[MAX_N];
double r[MAX_N];

double distTable[MAX_N][MAX_N];
double d[MAX_N];

double calcDist(double x1, double x2, double y1, double y2, double r1, double r2) {
    return max(0.0, sqrt((x1 - x2) * (x1 - x2) +
                (y1 - y2) * (y1 - y2)) - r1 - r2);
}


int main() {
    for(int i=0;i<MAX_N;i++) {
        d[i] = 1e20;
    }
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    for(int i=1; i < N + 1; i++) {
        cin >> x[i] >> y[i] >> r[i];
        // scanf("%llf %llf %llf", x+i, y+i, r+i);
    }
    x[0] = xs;
    y[0] = ys;
    r[0] = 0;
    x[N+1] = xt;
    y[N+1] = yt;
    r[N+1] = 0;
    for(int i=0; i<N+2; i++) {
        for(int j=i+1; j<N+2; j++) {
            distTable[i][j] = calcDist(x[i], x[j], y[i], y[j], r[i], r[j]);
            distTable[j][i] = calcDist(x[i], x[j], y[i], y[j], r[i], r[j]);
            // if(x[i] <= x[j] && y[i] <= y[j])
            //     distTable[i][j] = calcDist(x[i], x[j], y[i], y[j], r[i], r[j]);
            // if(x[j] <= x[i] && y[j] <= y[i])
            //     distTable[j][i] = calcDist(x[i], x[j], y[i], y[j], r[i], r[j]);
            // printf("distTable[%d][%d]: %f\n", i, j, distTable[i][j]);
        }
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        double value = t.first;
        int index = t.second;
        for(int i=0;i<N+2;i++) {
            if(value + distTable[index][i] < d[i]) {
                d[i] = value + distTable[index][i];
                q.push(make_pair(d[i], i));
            }
        }
    }
    printf("%.10f\n", d[N+1]);
}