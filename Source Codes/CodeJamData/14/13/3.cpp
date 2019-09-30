#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
int a[1024];
int b[1024][1024];

void init() {
    int trials = 5000000;
    int n = 1000;
    
    while (trials --) {
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int x = rand() % n;
            swap(a[x], a[i]);
        }
        
        for (int i = 0; i < n; i++) {
            b[ a[i] ][i] ++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf ("%d ", b[i][j]);
        }
    }
    printf ("\n");
}

void readInfo() {
    FILE *fin = fopen ("dump", "r");
    n = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%d", &b[i][j]);
        }
    }
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

vector<pair<int,int> > f;

void solve(int num) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        cnt += b[ a[i] ][i];
    }
    f.push_back(make_pair(cnt, num));
 
 //   printf ("%d\n", cnt);
}

int ans[130];

int main() {
    int cases;
    
    readInfo();
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        solve(i);
    }
    
    sort(f.begin(), f.end());
    
    for (int i = 0; i < cases / 2; i++) {
        ans[ f[i].second ] = 1;
    }
    
    for (int i = 1; i <= cases; i++) {
        printf ("Case #%d: ", i);
        if (ans[i] == 1) {
            printf ("GOOD\n");
        } else {
            printf ("BAD\n");
        }
    }
    
    return 0;
}
