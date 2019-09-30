#include <vector>
#include <cstdio>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
template <class T> bool setmin(T & l, T const & r) { if (not (r < l)) return false; l = r; return true; }
using namespace std;
typedef uint32_t mask_t;
int  left(int i) { return 2*i+1; }
int right(int i) { return 2*i+2; }
void rec(vector<mask_t> & t, int i, int il, int ir, int k, mask_t mask, int l, int r, mask_t z) {
    if (l <= il and ir <= r) {
        t[i] ^= z;
    } else if (ir <= l or r <= il) {
        // nop
    } else {
        mask ^= t[i];
        bool is_reversed = mask & (1<<k);
        int im = (il+ir)/2;
        int ll = min(l, im);
        int lr = min(r, im);
        int rl = max(l, im);
        int rr = max(r, im);
        if (is_reversed) {
            ll += im - il;
            lr += im - il;
            rl -= im - il;
            rr -= im - il;
            swap(ll, rl);
            swap(lr, rr);
        }
        rec(t,  left(i), il, im, k-1, mask, ll, lr, z);
        rec(t, right(i), im, ir, k-1, mask, rl, rr, z);
    }
}
int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<mask_t> t((1<<n)-1);
    repeat (query,q) {
        int type, a, b; scanf("%d%d%d", &type, &a, &b); -- a;
        if (type == 1) {
            assert (b == 0);
            int i = 0;
            mask_t mask = 0;
            repeat_reverse (k,n) {
                bool is_right = a & (1<<k);
                mask ^= t[i];
                bool is_reversed = mask & (1<<k);
                if (is_reversed) is_right = not is_right;
                i = is_right ? right(i) : left(i);
            }
            printf("%d\n", i-((1<<n)-1)+1);
        } else if (type == 2) {
            repeat (i,n) {
                int l = (1<<i) - 1;
                int r = 2*l + 1;
                setmax(l, a);
                setmin(r, b);
                if (r <= l) continue;
                int j = (1<<i) - 1;
                int k = n-1-i;
                l -= j; l <<= k;
                r -= j; r <<= k;
                rec(t, 0, 0, 1<<(n-1), n-1, 0, l, r, 1<<k);
            }
        }
    }
    return 0;
}