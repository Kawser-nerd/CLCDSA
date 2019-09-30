#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[100][101];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, a, f = 0, j;
        vector <int> v;
        
        scanf("%d %d", &n, &a);
        
        for (j = 0; j < n; j++) scanf("%s", s[j]);
        
        for (j = 0; j < n; j++) v.push_back(j);
        
        do {
            int x = v[0];
            
            for (j = 1; j < n; j++) {
                if (s[x][v[j]] == 'N') x = v[j];
            }
            
            if (x == a) {
                f = 1;
                
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
        
        if (f == 0) {
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
        } else {
            printf("Case #%d:", i + 1);
            for (j = 0; j < n; j++) printf(" %d", v[j]);
            puts("");
        }
    }
    
    return 0;
}
