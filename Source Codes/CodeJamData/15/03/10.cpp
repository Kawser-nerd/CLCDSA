#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define O 1
#define I 2
#define J 3
#define K 4

using namespace std;

typedef long long ll;

int S[4][4] = {
    {1, I, J, K},
    {I, -1, K, -J},
    {J, -K, -1, I},
    {K, J, -I, -1}
};

char C[] = "ijk";
int V[] = {I,J,K};

int toi(char ch) {
    FO(i,0,3) if (C[i] == ch) return V[i];
    assert(false);
    return 0;
}

int mul(int a, int b) {
    int s = 1;
    if (a < 0) {
        s *= -1;
        a *= -1;
    }
    if (b < 0) {
        s *= -1;
        b *= -1;
    }
    return s * S[a-1][b-1];
}

int pw(int a, ll b) {
    int r = 1;
    while (b) {
        if (b&1) r = mul(r,a);
        a = mul(a,a);
        b /= 2;
    }
    return r;
}

int ldiv(int y, int i) {
    // solve x*i = y
    FO(x,1,5) if (mul(x,i) == y) return x;
    FO(x,1,5) if (mul(-x,i) == y) return -x;
    assert(false);
    return 0;
}

int rdiv(int y, int i) {
    // solve i*x = y
    FO(x,1,5) if (mul(i,x) == y) return x;
    FO(x,1,5) if (mul(i,-x) == y) return -x;
    assert(false);
    return 0;
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int l; ll x;
        scanf("%d %lld", &l, &x);
        vector<char> s(l+1); scanf("%s", &s[0]);
        vector<int> v(l); FO(i,0,l) v[i] = toi(s[i]);

        vector<int> pref(l+1), suff(l+1);
        pref[0] = suff[0] = 1;
        FO(i,1,l+1) pref[i] = mul(pref[i-1], v[i-1]);
        FO(i,1,l+1) suff[i] = mul(v[l-i], suff[i-1]);

        map<int,int> fpref, fsuff;
        FO(i,0,l+1) {
            if (!fpref.count(pref[i])) {
                fpref[pref[i]] = i;
            }
            if (!fsuff.count(suff[i])) {
                fsuff[suff[i]] = i;
            }
        }

        char ans[50]; sprintf(ans, "Case #%d: ", Z);
        if (pw(pref[l], x) != -1) {
            strcat(ans, "NO");
        } else {
            ll spref = 1e17;
            set<int> seen;
            int c = 1;
            FO(i,0,x+1) {
                if (seen.count(c)) break;
                seen.insert(c);

                if (fpref.count(rdiv(I,c))) {
                    spref = i*l + fpref[rdiv(I,c)];
                    break;
                }

                c = mul(c,pref[l]);
            }

            ll ssuf = 1e17;
            seen.clear();
            c = 1;
            FO(i,0,x+1) {
                if (seen.count(c)) break;
                seen.insert(c);

                if (fsuff.count(ldiv(K,c))) {
                    ssuf = i*l + fsuff[ldiv(K,c)];
                    break;
                }

                c = mul(suff[l],c);
            }

            if (spref+ssuf < x*l) {
                strcat(ans, "YES");
            } else {
                strcat(ans, "NO");
            }
        }
        printf("%s\n",ans);
    }
}

