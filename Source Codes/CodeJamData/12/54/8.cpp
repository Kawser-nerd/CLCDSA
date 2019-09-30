#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 8192;
const int MAXM = 50;

const char exchange[] = "oieastbg";
char buf[MAXN];
bool w[MAXM][MAXM], d[MAXM];

int c2i(char ch) {
    return ch - 'a';
}

int c2j(char ch) {
    const char* p = strchr(exchange, ch);
    return p != NULL ? 26 + (p - exchange) : c2i(ch);
}

int main() {
    int re, n, m, sum, diff;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%s", &m, buf);
        n = strlen(buf);
        fill(w[0], w[MAXM], false);
        for (int i = 1; i < n; ++i) {
            w[c2i(buf[i - 1])][c2i(buf[i])] = true;
            w[c2i(buf[i - 1])][c2j(buf[i])] = true;
            w[c2j(buf[i - 1])][c2i(buf[i])] = true;
            w[c2j(buf[i - 1])][c2j(buf[i])] = true;
        }
        sum = diff = 0;
        for (int i = 0; i < MAXM; ++i) {
            int in = 0, out = 0;
            for (int j = 0; j < MAXM; ++j) {
                if (w[i][j]) {
                    ++out;
                }
                if (w[j][i]) {
                    ++in;
                }
            }
            if (in != out) {
                diff = 1;
            }
            sum += max(in, out);
        }
        sum -= diff;
        printf("Case #%d: %d\n", ri, sum + 1);
    }

    return 0;
}

