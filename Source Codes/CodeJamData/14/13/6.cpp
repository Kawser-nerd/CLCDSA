#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << (a) << endl;
typedef long long ll;
typedef pair<int, int> pii;
#define MP make_pair
#define A first
#define B second

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
int N;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        cin >> N;
        for (int i=0; i<N; i++)
            cin >> a[i];
        int cnt = 0;
        for (int i=0; i<N; i++)
            if (a[i] < i)
                cnt++;
        if (cnt > 485)
            cout << "GOOD\n";
        else
            cout << "BAD\n";
    }
    return 0;
}
