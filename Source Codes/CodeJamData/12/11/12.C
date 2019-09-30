#include<cstdio>
#include<cstdlib>
#include<cstring>
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
#include<gmpxx.h>

using namespace std;

mpf_class compute(int A, int B, int d, const vector<mpf_class> &p)
{
    assert(d >= 0 && d < A);
    // double pall = 1.0;
    // for(int i = 0; i < A - d; ++i) {
    //     pall *= p[i];
    // }
    return 1. + 2. * d + B - A + (1. - p[A - d - 1]) * (1 + B);
}

void do_case(void)
{
    int A, B;
    cin >> A >> B;

    vector<mpf_class> p;

    mpf_class last(1.0, 1000);
    for(int i = 0; i < A; ++i) {
        double t;
        cin >> t;
        last *= t;
        p.push_back(last);
    }

    double min = B + 2;
    for(int d = 0; d < A; ++d) {
        mpf_class val = compute(A, B, d, p);
        min = min < val ? min : val.get_d();
    }
    printf("%.10f\n", min);
}

int main()
{
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
