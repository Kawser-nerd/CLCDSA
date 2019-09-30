#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

const int N = 1000;
vector<vector<double> > prob;

void calculateBadProb()
{
    prob.assign(N, vector<double>(N, 0.0));
    for(int i=0; i<N; ++i)
        prob[i][i] = 1.0;

    for(int k=0; k<N; ++k){
        vector<vector<double> > nextProb(N, vector<double>(N, 0.0));
        for(int j=0; j<N; ++j){
            for(int i=0; i<N; ++i)
                nextProb[k][j] += prob[i][j];
            nextProb[k][j] /= N;

            for(int i=0; i<N; ++i){
                if(i != k)
                    nextProb[i][j] = (prob[i][j] * (N - 1) + prob[k][j]) / N;
            }
        }
        prob.swap(nextProb);
    }
}

string solve()
{
    int tmp;
    cin >> tmp;

    double x = 0.0;
    double y = 0.0;
    for(int i=0; i<N; ++i){
        int a;
        cin >> a;
        x += log(prob[i][a]);
        y += log(1.0 / N);
    }

    if(x > y)
        return "BAD";
    else
        return "GOOD";
}

int main()
{
    calculateBadProb();

    int T;
    cin >> T;

    for(int tc=1; tc<=T; ++tc){
        string ret = solve();
        cout << "Case #" << tc << ": " << ret << endl;
    }

    return 0;
}