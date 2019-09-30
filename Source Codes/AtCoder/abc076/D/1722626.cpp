#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define INF 100100100

using namespace std;

int main()
{
    int N;
    vector<int> t;
    vector<int> cumt;
    vector<int> v;
    t.push_back(0);
    cumt.push_back(0);
    cumt.push_back(0);
    v.push_back(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int ti;
        cin >> ti;
        ti *= 2;
        t.push_back(ti);
        cumt.push_back(cumt[i + 1] + ti);
    }
    for (int i = 0; i < N; i++)
    {
        int vi;
        cin >> vi;
        v.push_back(vi * 2);
    }
    t.push_back(0);
    v.push_back(0);
    cumt.push_back(*(cumt.end() - 1));

    int T = *(cumt.end() - 2);

    int vs = 0.0;
    int ve;
    int ans = 0;
    for (int i = 0; i < T; i++)
    {
        int minv = INF;
        for (int j = 0; j < N + 3; j++)
        {
            int limv;
            int curt = i + 1;
            if (curt <= cumt[j])
            {
                limv = v[j] + cumt[j] - curt;
            }
            else if (cumt[j] <= curt && curt <= cumt[j + 1])
            {
                limv = v[j];
            }
            else if (cumt[j + 1] <= curt)
            {
                limv = v[j] + curt - cumt[j + 1];
            }

            minv = min(minv, limv);
        }
        if (vs + 1 <= minv)
        {
            ve = vs + 1;
        }
        else if (vs == minv)
        {
            ve = vs;
        }
        else
        {
            ve = vs - 1;
        }
        ans += vs + ve;
        vs = ve;
    }

    cout << setprecision(15) << ans / 8.0 << endl;

    return 0;
}