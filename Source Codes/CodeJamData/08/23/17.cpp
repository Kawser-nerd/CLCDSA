#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


struct RSQ
{
	int n;
	int base;
	int size;	
	vector <int> a;
	RSQ(int n)
	{
		this->n = n;
		base = 2;
		int leaves = 2;
		while (leaves < n)
		{
			base += leaves;
			leaves *= 2;
		}
		size = base + leaves;
		a = vector<int> (size, 0);
	}
    int get(int i)
    {
        return a[base  + i];
    }
	void set(int i, int value)
	{
		a[base + i] = value;
		for (int k = (base + i) / 2; k >= 1; k /= 2)
		{
			a[k] = a[2 * k] + a[2 * k + 1];
		}
	}
	int getSum(int lo, int up)
	{
        if (lo > up) return 0;
		lo += base;
		up += base;
		if (lo == up) return a[lo];
		int res = a[lo] + a[up];
		for (int pl = lo / 2, pu = up / 2; pl != pu; lo = pl, up = pu, pl /= 2, pu /= 2)
		{
			if (2 * pl + 1 != lo) res += a[2 * pl + 1];
			if (2 * pu + 0 != up) res += a[2 * pu + 0];
		}
		return res;
	}
    int getZeros(int lo, int up)
    {
        if (lo > up) return 0;
        return up - lo + 1 - getSum(lo, up);
    }
    int getIdx(int lo, int up, int pos)
    {
        if (pos == 1 && get(lo) == 0) return lo;
        int mid = (lo + up) / 2;
        int x = getZeros(lo, mid);
        if (pos <= x) return getIdx(lo, mid, pos);
        return getIdx(mid + 1, up, pos - x);
    }

};

const int N = 1000002;
int a[N];

int main()
{
    freopen("clarge.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int cc = 1; cc <= TC; ++cc)
    {
        int K, n;
        int d[100];
        cin >> K >> n;
        for (int i = 0; i < n; ++i)
            cin >> d[i];
        RSQ rsq(K + 2);
        rsq.set(1, 1);
        a[1] = 1;
        for (int k = 2, at = 1; k <= K; ++k)
        {
            int pos = (k - 1) % (K - k + 1);
            int right = rsq.getZeros(at, K);
            int idx;
            if (pos < right)
            {
                idx = rsq.getIdx(at, K, pos + 1);
            }
            else
            {
                pos -= right;
                idx = rsq.getIdx(1, at, pos + 1);
            }
            rsq.set(idx, 1);
            a[idx] = k;
            at = idx;
        }
        
        printf("Case #%d:", cc);
        for (int i = 0; i < n; ++i)
            printf(" %d", a[d[i]]);
        printf("\n");
    }
    return 0;
}
