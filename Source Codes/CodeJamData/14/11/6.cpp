#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << (a) << endl;
typedef long long ll;
typedef pair<int, int> pii;
#define MP make_pair
#define A first
#define B second

const int INF = 0x3f3f3f3f;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        int ans = INF;
        int n, l; cin >> n >> l;
        vector<string> out(n), dev(n);
        for (int i=0; i<n; i++) cin >> out[i];
        for (int i=0; i<n; i++) cin >> dev[i];
        set<string> devices;
        for (int i=0; i<n; i++) devices.insert(dev[i]);
        for (int i=0; i<n; i++) // which dev to put first out to
        {
            int cur = 0;
            for (int k=0; k<l; k++)
                if (out[0][k] != dev[i][k])
                    cur++;

            set<string> outlets;
            for (int j=0; j<n; j++)
            {
                string outl;
                for (int k=0; k<l; k++)
                {
                    // outlet
                    if (out[0][k] == dev[i][k])
                        outl += out[j][k];
                    else
                        outl += !(out[j][k]-'0') + '0';
                }
                outlets.insert(outl);
            }
            if (outlets == devices)
                ans = min(ans, cur);
        }
        if (ans == INF)
            cout << "NOT POSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
