#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

const long INF = 1e9;

using namespace std;

int main() {
    int n, t, a;
    vector<long> h;

    long temp;
    double evaluate = INF;
    int index = -1;


    cin >> n >> t >> a;

    for (int i = 0; i < n; i++){
        cin >> temp;
        h.push_back(temp);
    }

    for (int i = 0; i < n; i++){
        double this_temp = (double)t - double(h.at(i)) * 0.006;
        double this_diff = abs(this_temp - a);
        if (this_diff < evaluate){
            evaluate = this_diff;
            index = i + 1;
        }
    }
    cout << index << endl;

    return 0;
}