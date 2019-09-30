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

using namespace std;

void update(vector<int> &amp, const vector<int> &d, const vector<int> &l, int i, int N)
{
    int myamp = amp[i];
    for(int j = i + 1; j < N; ++j) {
        if(d[j] > d[i] + myamp) break;
        int v = l[j] < d[j] - d[i] ? l[j] : d[j] - d[i];
        if(v > amp[j]) amp[j] = v;
    }
}

void do_case(void)
{
    int N;
    cin >> N;
    vector<int> d, l;

    for(int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        d.push_back(a);
        l.push_back(b);
    }
    int D;
    cin >> D;

    vector<int> amp(N, 0);
    amp[0] = d[0];

    for(int i = 0; i < N; ++i) {
        update(amp, d, l, i, N);
        if(amp[i] + d[i] >= D) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
