#include <stdio.h>
#include <string.h>

int main()
{
    int t, i, j, l;
    char c[11] = "oi eas tbg";
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int k, n, sum = 0, f = 0;
        char s[1001];
        int a[26][26] = {0};
        int b[36][2] = {0};
        
        scanf("%d", &k);
        scanf("%s", s);
        
        n = strlen(s);
        
        for (j = 0; j < n - 1; j++) {
            int x = s[j] - 'a';
            int y = s[j + 1] - 'a';
            int p = -1, q = -1;
            
            if (a[x][y] == 1) continue;
            
            a[x][y] = 1;
            
            b[x][0]++;
            b[y][1]++;
            
            for (l = 0; l < 10; l++) {
                if (s[j] == c[l]) p = l;
                if (s[j + 1] == c[l]) q = l;
            }
            
            if (p != -1) {
                if (q != -1) {
                    b[x][0]++;
                    b[y][1]++;
                    b[26 + p][0] += 2;
                    b[26 + q][1] += 2;
                } else {
                    b[26 + p][0]++;
                    b[y][1]++;
                }
            } else if (q != -1) {
                b[x][0]++;
                b[26 + q][1]++;
            }
        }
        
        for (j = 0; j < 36; j++) {
            if (b[j][0] > b[j][1]) {
                sum += b[j][0];
            } else {
                sum += b[j][1];
            }
            
            if (b[j][0] != b[j][1]) f = 1;
        }
        
        if (f == 0) sum++;
        
        printf("Case #%d: %d\n", i + 1, sum);
    }
    
    return 0;
}
