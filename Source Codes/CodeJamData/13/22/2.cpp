#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int N,X,Y;
int combi[505][505];

void precalc() {
    memset(combi, 0, sizeof(combi));
    for(int i=1;i<=500;i++) {
        combi[i][0] = combi[i][i] = 1;
        for(int j=1;j<i;j++) {
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
        }
    }
}

void process(void) {
    scanf("%d %d %d",&N, &X, &Y);
    int layer = (abs(X) + abs(Y)) / 2;
    if(layer == 0) {
        cout << "1.0" << endl;
        return;
    }
    layer--;
    int minrange = (2*layer+1) * (layer+1);
    layer++;
    int maxrange = (2*layer+1) * (layer+1);

    if(N <= minrange) {
        cout << "0.0" << endl;
        return;
    }
    if(N >= maxrange) {
        cout << "1.0" << endl;
        return;
    }

    if(X == 0) {
        cout << "0.0" << endl;
        return;
    }

    int given = N - minrange;

//    cout << "given = " << given << endl;

    vector<double> cur, nex;
    cur.resize(2, 0.5);
    for(int i=2;i<=given;i++) {
        nex = vector<double>(i+1);

        for(int j=0;j<i;j++) {
            int right = i-1-j;
            if(j > layer*2 || right > layer*2) continue;
            if(j == layer*2) {
                nex[j] += cur[j];
                continue;
            }
            if(right == layer*2) {
                nex[j+1] += cur[j];
                continue;
            }
            nex[j] += cur[j] * 0.5;
            nex[j+1] += cur[j] * 0.5;
        }
        cur.swap(nex);
    }

    double ret = 0;
    for(int i=Y+1;i<size(cur);i++) ret += cur[i];

    printf("%.12lf\n", ret);
}

int main(void)
{
    precalc();
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
