#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash() = default;
    
  void set(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH = RollingHash< 1000000007 >;

int main() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] += s[i];
    }
    
    vector<string> tmp = s;
    
    s.insert(s.end(), tmp.begin(), tmp.end());
        
    vector<string> t(s.size(), string(2 * n, 0));
    
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            t[i][j] = s[j][i];       
        }
    }
    
    vector<RH> sh(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        sh[i].set(s[i]);
    }
    
    vector<RH> th(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        th[i].set(t[i]);
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //if (sh[i].get(j, j + n) == th[j].get(i, i + n)) {
            bool ok = true;
            
            for (int k = 0; k < n; k++) {
                if (memcmp(s[i + k].c_str() + j, t[j + k].c_str() + i, n) != 0) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}