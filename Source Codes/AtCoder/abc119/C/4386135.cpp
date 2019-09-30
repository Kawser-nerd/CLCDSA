#include <iostream>
#include <vector>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int to_num(int k1, int k2) {
    int ret = 0;
    if (k1) ret+=2;
    if (k2) ret+=1;
    return ret;
}


int main() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> l(n); rep(i, n) cin >> l[i];
    int ans = 1001001001;

    rep (i, 1<<n) {
        rep (j, 1<<n) {
            // i, j ??? 1+1 ??????? [0..4] ???

            int a_ = 0;
            int b_ = 0;
            int c_ = 0;
            int syn = 0;

            rep (k, n) {
                int option = to_num(i>>k&1, j>>k&1);
                if (option == 0) {
                    if (a_ != 0) syn++;
                    a_ += l[k];
                }
                if (option == 1) {
                    if (b_ != 0) syn++;
                    b_ += l[k];
                }
                if (option == 2) {
                    if (c_ != 0) syn++;
                    c_ += l[k];
                }
            }

            // ??????????
            if (a_==0 || b_==0 || c_==0) continue;

            ans = min(ans, abs(a-a_)+abs(b-b_)+abs(c-c_)+10*syn);
        }
    }

    cout << ans << endl;
}