#include <cstdio>
#include <algorithm>
using namespace std;

int R, C, K, Sr, Sc;
bool m[805][805];
int dist[805][805];

int minr = 1e9, maxr, minc = 1e9, maxc;

bool seen[805][805];
int sr[10000000], sc[10000000], ss, se;

void push(int r, int c, int d) {
    if (seen[r][c] || !m[r][c]) return;
    seen[r][c] = 1;
    sr[se] = r;
    sc[se++] = c;
    dist[r][c] = d;
}

int main() {
    scanf("%d %d %d", &R, &C, &K);
    char s;
    for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
        scanf(" %c", &s);
        m[r][c] = 1;
        if (s == '#') m[r][c] = 0;
        else if (s == 'S') Sr = r, Sc = c;
    }
    sr[se] = Sr, sc[se++] = Sc;
    seen[Sr][Sc] = 1;
    while (ss < se) {
        int r = sr[ss], c = sc[ss];
        ss++;
        if (r < minr) minr = r;
        if (r > maxr) maxr = r;
        if (c < minc) minc = c;
        if (c > maxc) maxc = c;
        if (dist[r][c] < K) {
            push(r+1,c,dist[r][c]+1);
            push(r-1,c,dist[r][c]+1);
            push(r,c+1,dist[r][c]+1);
            push(r,c-1,dist[r][c]+1);
        }
    }

    int d = min(min(minr-1,minc-1),min(R-maxr,C-maxc));
    printf("%d\n", 1 + (d+K-1)/K);
}