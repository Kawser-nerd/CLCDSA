#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

char s[105];

const int C = 26, MOD = 1000000007, M = 105;

struct Trie;

vector<Trie*> node;

int fac[105], rev[105];

int cb(int n, int m) {
    return (long long)fac[n] * rev[m] % MOD * rev[n - m] % MOD;
}

struct Trie {
    Trie *ch[C];
    int ans, cnt, size;
    bool leaf;

    Trie() {
        memset(ch, 0, sizeof(ch));
        ans = cnt = size = 0;
        leaf = false;
        node.push_back(this);
    }

    void insert(char *s) {
        ++size;
        if (*s == '\0') {
            leaf = true;
            return;
        }
        int c = *s - 'A';
        if (!ch[c]) {
            ch[c] = new Trie();
        }
        ch[c]->insert(s + 1);
    }

    void getans() {
        int maxch = 0;
        ans = min(size, m);
        for (int i = 0; i < C; ++i) {
            if (ch[i]) {
                ch[i]->getans();
                ans += ch[i]->ans;
                maxch = max(maxch, ch[i]->size);
            }
        }
        if (size <= m) {
            cnt = fac[size];
        } else {
            if (leaf) {
                cnt = m;
            } else {
                cnt = 1;
            }
            if (maxch >= m) {
                for (int i = 0; i < C; ++i) {
                    if (ch[i]) {
                        cnt = (long long)cnt * cb(m, min(m, ch[i]->size)) % MOD * ch[i]->cnt % MOD;
                    }
                }
            } else {
                int f[M];
                memset(f, 0, sizeof(f));
                for (int i = 1; i <= m; ++i) {
                    f[i] = leaf ? i : 1;
                }
                for (int i = 0; i < C; ++i) {
                    if (ch[i]) {
                        for (int j = 1; j <= m; ++j) {
                            if (j < ch[i]->size) {
                                f[j] = 0;
                            } else {
                                f[j] = (long long)f[j] * fac[j] % MOD * rev[j - ch[i]->size] % MOD;
                            }
                        }
                    }
                }
                for (int i = 1; i <= m; ++i) {
                    for (int j = i - 1; j >= 1; --j) {
                        f[i] = (f[i] - (long long)cb(i, j) * f[j] % MOD + MOD) % MOD;
                    }
                }
                cnt = f[m];
            }
        }
    }
};

int inv(int a) {
    return a == 1 ? a : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        fac[i] = (long long)fac[i - 1] * i % MOD;
    }
    for (int i = 0; i <= 100; ++i) {
        rev[i] = inv(fac[i]);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        Trie *root = new Trie();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            root->insert(s);
        }
        root->getans();
        static int id = 0;
        printf("Case #%d: %d %d\n", ++id, root->ans, root->cnt);
        for (int i = 0; i < (int)node.size(); ++i) {
            delete node[i];
        }
        node.clear();
    }
    return 0;
}
