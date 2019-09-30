#pragma comment (linker, "/STACK:256000000")
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <climits>
using namespace std;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<vi, vi> pvivi;

struct TSolveResult {
    vi First;
    vi Second;
    ll Diff;
};

TSolveResult Solve(const vl& nums, int addVal = 0) {
    int n = nums.size();
    if (n > 25)
        throw std::exception("too large subtask");
    vector< pair<ll, int> > subsets(1<<n);
    cerr << "l1" << endl;
    for (int i = 1; i < (int)(1<<n); ++i) {
        subsets[i].first = 0;
        subsets[i].second = i;
        for (int j = 0; j < n; ++j)
            if ((1<<j) & i)
                subsets[i].first += nums[j];
    }
    cerr << "l2" << endl;
    ll resAbs = LLONG_MAX;
    int res1 = -1, res2 = -1;
    sort(subsets.begin(), subsets.end());
    cerr << "l3" << endl;
    for (int i = 0; i + 1 < (int)subsets.size(); ++i) {
        if (subsets[i+1].first - subsets[i].first < resAbs) {
            resAbs = subsets[i+1].first - subsets[i].first;
            res1 = subsets[i].second;
            res2 = subsets[i+1].second;
        }
    }
    cerr << "l4" << endl;
    if (res1 == -1)
        throw std::exception("WHAT THE FUCK!");
    TSolveResult res;
    for (int i = 0; i < n; ++i) {
        bool b1 = (0 != (res1 & (1<<i)));
        bool b2 = (0 != (res2 & (1<<i)));
        if (b1 && !b2)
            res.First.push_back(i + addVal);
        if (b2 && !b1)
            res.Second.push_back(i + addVal);
    }
    cerr << "l5" << endl;
    res.Diff = resAbs;
    cerr << "l6" << endl;
    return res;
}

int main(void) {
    try {
    int testCount;
    cin >> testCount;
    for (int testNo = 1; testNo <= testCount; ++testNo) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i< n; ++i)
            cin >> nums[i];
        
        vector<TSolveResult> solveResults(n / 20);
        vector<ll> nums2(n / 20);
        for (int i = 0; i < n; i+=20) {
            solveResults[i/20] = Solve(vl(nums.begin() + i, nums.begin() + i + 20), i);
            nums2[i/20] = solveResults[i/20].Diff;
            cerr << nums2[i/20] << endl;
        }
        TSolveResult res = Solve(nums2);
        if (res.Diff != 0)
            throw std::exception();
        cout << "Case #" << testNo << ":" << endl;
        vi res1, res2;
        for each (int i in res.First) {
            for each (int j in solveResults[i].First)
                res1.push_back(j);
            for each (int j in solveResults[i].Second)
                res2.push_back(j);
        }
        for each (int i in res.Second) {
            for each (int j in solveResults[i].First)
                res2.push_back(j);
            for each (int j in solveResults[i].Second)
                res1.push_back(j);
        }
        for each (int i in res1) {
            cout << nums[i] << " ";
        }
        cout << endl;
        for each (int i in res2) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
