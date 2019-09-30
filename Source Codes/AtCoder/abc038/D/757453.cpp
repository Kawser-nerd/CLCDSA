#include <iostream>
#include <algorithm>

#define MAX_SIZE 100000

using namespace std;

typedef pair<int, int> P;

template<class T>
class BinaryIndexedTree
{
    private:
        const size_t n;
        T a[MAX_SIZE + 1];
        const T LOWER_BOUND;
    public:
        int query(T i)
        {
            T ret = LOWER_BOUND;
            while (i > 0) {
                ret = max(ret, a[i]);
                i -= i & -i;
            }
            return ret;
        }
        void update(size_t i, T x)
        {
            a[i] = max(a[i], x);
            T parent;
            while ((parent = i + (i & -i)) <= n) {
                a[parent] = max(a[parent], a[i]);
                i = parent;
            }
        }
        void show(size_t first = 0, size_t end = MAX_SIZE)
        {
            for (size_t i = first + 1; i < end + 1; i++) {
                cout << "a[" << i << "] = " << a[i] << endl;
            }
        }
        BinaryIndexedTree(size_t m = 50, T lb = 0) : n(m), LOWER_BOUND(lb)
        {
            for (size_t i = 0; i <= n; i++) {
                a[i] = LOWER_BOUND;
            }
        }
        size_t size()
        {
            return n;
        }
        T lower_bound()
        {
            return LOWER_BOUND;
        }
};

bool comp(P p, P q)
{
    if (p.second < q.second) {
        return true;
    }
    if (p.second == q.second && p.first > q.first) {
        return true;
    }
    return false;
}

int main(void)
{
    int n;
    P wh[MAX_SIZE];
    unsigned long long dp[MAX_SIZE];
    cin >> n;
    BinaryIndexedTree<int> bit(MAX_SIZE);
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w;
        cin >> h;
        wh[i] = P(w, h);
    }
    //cout << "n = " << n << endl;
    sort(wh, wh + n, comp);
    for (int i = 0; i < n; i++) {
        P p = wh[i];
        int w = p.first, h = p.second;
        //cout << w << " " << h << endl;
        dp[i] = bit.query(w - 1) + 1;
        bit.update(w, dp[i]);
        //bit.show(0, 10);
    }
    unsigned long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, dp[i]);
        //cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << ret << endl;
    return 0;
}