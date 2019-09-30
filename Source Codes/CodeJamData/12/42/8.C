#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<fstream>
#include<iostream>
#include<bitset>
#include<cassert>
#include<climits>
#include<vector>
#include<queue>
#include<string>

using namespace std;

bool can_place(const vector<unsigned> &r,
               const vector<double> &x,
               const vector<double> &y,
               int i)
{
    for(int j = 0; j < i; ++j) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        double rs = r[i] + r[j];
        if(dx * dx + dy * dy < rs * rs) return false;
    }
    return true;
}

void do_case(void)
{
    unsigned N, W, L;
    cin >> N >> W >> L;

    vector<unsigned> r;
    for(int i = 0; i < N; ++i) {
        unsigned ri;
        cin >> ri;
        r.push_back(ri);
    }
    // sort(r.rbegin(), r.rend());

    vector<double> x(N, 0);
    vector<double> y(N, 0);

    for(int i = 0; i < N; ++i) {
        do {
            x[i] = drand48() * W;
            y[i] = drand48() * L;
        } while(!can_place(r, x, y, i));
    }
    
    for(int i = 0; i < N; ++i) {
        printf("%.12g %.12g ", x[i], y[i]);
    }
    printf("\n");
}

int main()
{
    srand48(100);
    // srand48((unsigned long)time(NULL));
    freopen("input.data", "r", stdin);
    //freopen("output.data", "r", stdout);

    int cases;
    scanf("%d\n", &cases);
    int i = 1;
    do{
        printf("Case #%d: ", i);
        do_case();
    }while(++i <= cases);

    return 0;
}
