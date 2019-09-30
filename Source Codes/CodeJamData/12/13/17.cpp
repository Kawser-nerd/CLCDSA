#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
// using namespace std::rel_ops;

const int MAXN = 200000;

struct DisjointSet {
    int p[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
    }

    int getp(int i) {
        if (i < 0) {
            return -getp(-i);
        } else if (p[i] == i) {
            return i;
        } else {
            return p[i] = getp(p[i]);
        }
    }

    bool setp(int i, int j) {
        i = getp(i);
        j = getp(j);
        if (i == -j) {
            return false;
        } else {
            if (i < 0) {
                i = -i;
                j = -j;
            }
            p[i] = j;
            return true;
        }
    }
} ds;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    long long num, den;
    Fraction(int n = 0, int d = 1) {
        int g = gcd(abs(n), abs(d));
        num = n / g;
        den = d / g;
    }
    bool operator<(const Fraction& that) const {
        return num * that.den < that.num * den;
    }
};

struct Car {
    int id;
    bool fixed;
    char lane;
    int speed;
    int position;
    vector<pair<pair<Fraction, Fraction>, int> > invalid;
} car[MAXN];

const int LEN = 5;
const int INF = 1000000007;

vector<Fraction> v;
map<Fraction, int> mp;
vector<pair<int, int> > op[MAXN];

void gao(Car& a, Car& b) {
    if (a.speed < b.speed) {
        return gao(b, a);
    } else if (a.speed == b.speed) {
        if (abs(a.position - b.position) < 5) {
            a.fixed = b.fixed = true;
            a.invalid.push_back({{0, INF}, b.id});
            b.invalid.push_back({{0, INF}, a.id});
        }
    } else if (a.position < b.position + 5) {
        Fraction from;
        if (b.position - a.position >= 5) {
            from = Fraction(b.position - a.position - 5, a.speed - b.speed);
        } else {
            a.fixed = b.fixed = true;
        }
        Fraction to(b.position - a.position + 5, a.speed - b.speed);
        /*
        if (a.id == 3 && b.id == 0) {
            printf("%f %f\n", 1.0 * from.num / from.den, 1.0 * to.num / to.den);
        }
        */
        mp[from];
        mp[to];
        a.invalid.push_back({{from, to}, b.id});
        b.invalid.push_back({{from, to}, a.id});
    }
}

int n, m;

int var(int i, int j) {
    return i * m + j + 2;
}

void show(int x) {
    if (x < 0) {
        putchar('!');
        show(-x);
    } else if (x == 1) {
        putchar('T');
    } else {
        x -= 2;
        printf("(%d,%d)", x / m, x % m);
    }
}

int main() {
    int re;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            car[i].id = i;
            car[i].fixed = false;
            scanf(" %c%d%d", &car[i].lane, &car[i].speed, &car[i].position);
            car[i].invalid.clear();
        }
        mp.clear();
        mp[0];
        mp[INF];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i != j) {
                    gao(car[i], car[j]);
                }
            }
        }

        m = 0;
        v.clear();
        for (auto& p: mp) {
            v.push_back(p.first);
            op[m].clear();
            // printf("[%d] %lld/%lld\n", m, p.first.num, p.first.den);
            p.second = m++;
        }
        fprintf(stderr, "m = %d\n", m);

        for (int i = 0; i < n; ++i) {
            if (car[i].fixed) {
                op[0].push_back({var(i, 0), car[i].lane == 'L' ? 1 : -1});
            }
            // sort(car[i].invalid.begin(), car[i].invalid.end());
            for (const auto& x: car[i].invalid) {
                int s = mp[x.first.first];
                int t = mp[x.first.second];
                int j = x.second;
                for (int k = s + 1; k < t; ++k) {
                    op[k - 1].push_back({var(i, k - 1), var(i, k)});
                }
                for (int k = s; k < t; ++k) {
                    op[k].push_back({var(i, k), -var(j, k)});
                }
            }
        }

        ds.init(n * m + 2);
        for (int i = 0; i < m; ++i) {
            for (const auto& x: op[i]) {
                if (false) {
                    printf("do ");
                    show(x.first);
                    printf(" ");
                    show(x.second);
                    printf("\n");
                }
                if (!ds.setp(x.first, x.second)) {
                    printf("Case #%d: %.6f\n", ri, 1.0 * v[i].num / v[i].den);
                    goto NEXT;
                }
            }
        }
        printf("Case #%d: Possible\n", ri);
NEXT:
        fflush(stdout);
    }

    return 0;
}
