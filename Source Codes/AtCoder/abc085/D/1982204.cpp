#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct sword{
    int att, typ;
}a[200005];

bool cmp(sword a, sword b){
    return a.att > b.att;
}
int main(){
    memset(a, 0, sizeof a);
    int n, h;
    scanf("%d%d", &n, &h);
    int amax = -2147483647;
    for (int i = 0; i < n; i++){
        scanf("%d%d", &(a[2 * i].att), &(a[2 * i + 1].att));
        a[2 * i].typ = 1; a[2 * i + 1].typ = 0;
        amax = max(amax, a[2 * i].att);
    }
    sort(a, a + 2 * n, cmp);
    int i, attsum = 0, cnt;
    for (i = 0; i < 2 * n; i++){
        if (attsum >= h || a[i].typ){
            cnt = i;
            break;
        }
        attsum += a[i].att;
    }
    if (attsum < h) printf("%d", cnt + (int)ceil((double)(h - attsum) / amax));
    else printf("%d", cnt);
    puts("");
    return 0;
}