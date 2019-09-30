#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void init() {

}

char a[111][111];
bool vis[111];
int clow[111];
int chgh[111];
int totals_low[1<<25];
int totals_hgh[1<<25];
int totals_mern[1<<25];


map<pair<int,int>,int> bestc;
ll best(int mask, int low, int hgh) {
    if (!mask) {
        return 0;
    }
    pair<int,int> hsh = make_pair(mask, low | hgh);
    if (bestc.find(hsh) != bestc.end()) return bestc[hsh];
    int i = 0;
    while ((mask & (1<<i)) == 0) i++;
    mask ^= 1<<i;
    ll res = 1LL<<60;
    int s = 0;
    do {
        int tlow = totals_low[s | (1<<i)];
        int thgh = totals_hgh[s | (1<<i)];
        int tmern = totals_mern[s | (1<<i)];
        if (tlow <= thgh) {
            if (thgh - tlow <= low) {
                res = min(res, thgh*thgh - tmern + best(mask ^ s, low - (thgh - tlow), hgh));
            }
        } else {
            // assert thgh <= tlow
            if (tlow - thgh <= hgh) {
                res = min(res, tlow*tlow - tmern + best(mask ^ s, low, hgh - (tlow - thgh)));
            }
        }
    } while (s = s - 1 & mask);
    bestc[hsh] = res;
    return res;
}



ll solve() {
    bestc.clear();
    ll ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < n; j++) a[i][j] -= '0';

    }
    for (int i = 0; i < 2*n; i++) {
        vis[i] = false;
    }
    int cs = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        vector<int> queue;
        queue.push_back(i);
        for (int f = 0; f < queue.size(); f++) {
            int i = queue[f];
            if (i < n) {
                for (int j = n; j < 2*n; j++) {
                    if (a[i][j-n]) {
                        if (!vis[j]) {
                            vis[j] = true;
                            queue.push_back(j);
                        }
                    }
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (a[j][i-n]) {
                        if (!vis[j]) {
                            vis[j] = true;
                            queue.push_back(j);
                        }
                    }
                }
            }
        }

        int low = 0;
        int hgh = 0;
        for (int i = 0; i < queue.size(); i++) {
            if  (queue[i] < n) {
                low++;
            }
        }
        for (int j = 0; j < queue.size(); j++) {
            if (queue[j] >= n) {
                hgh++;
            }
        }
        for (int i = 0; i < queue.size(); i++) {
            if  (queue[i] < n) {
                for (int j = 0; j < queue.size(); j++) {
                    if (queue[j] >= n) {
                        if (!(a[queue[i]][queue[j]-n])) ans++;
                    }
                }
            }
        }
        if (low != hgh) {
            clow[cs] = low;
            chgh[cs] = hgh;
            cs++;
        }
    }
    int badlow = 0, badhgh = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) badlow++;
    for (int i = n; i < 2*n; i++) if (!vis[i]) badhgh++;
    while (badlow and badhgh) {
        badlow -= 1;
        badhgh -= 1;
        ans += 1;
    }

    for (int i = 0; i < cs; i++) {
        for (int mask = 0; mask < 1<<i; mask++) {
            totals_low[mask | (1<<i)] = totals_low[mask] + clow[i];
            totals_hgh[mask | (1<<i)] = totals_hgh[mask] + chgh[i];
            totals_mern[mask | (1<<i)] = totals_mern[mask] + clow[i] * chgh[i];
        }
    }
    // printf("%d %d %d [%lld]\n", cs,badlow, badhgh, ans);
    ans += best((1<<cs)-1, badlow, badhgh);

    return ans;
}

















int main() {
    init();
    int z;
    sf("%d", &z);
    fq(cas,z) {
        pf("Case #%d: %lld\n", cas, solve());
    }
}
