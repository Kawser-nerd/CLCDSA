/* Google Code Jam Round 1B 2016
 * Problem B. Close Match
 * Solution in C
 * By Smithers
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char c[20];
char j[20];

char ctemp[20];
char jtemp[20];

char cbest[20];
char jbest[20];

uint64_t best[3];

void go(int i, int mode)
{
    ctemp[i] = c[i];
    jtemp[i] = j[i];
    
    if (!c[i])
    {
        uint64_t score[3];
        
        score[1] = strtoull(ctemp, 0, 10);
        score[2] = strtoull(jtemp, 0, 10);
        
        score[0] = llabs((int64_t)score[1] - (int64_t)score[2]);
        
        if (score[0] < best[0]
            || score[0] == best[0]
               && (score[1] < best[1]
                   || score[1] == best[1]
                      && score[2] < best[2]))
        {
            strcpy(cbest, ctemp);
            strcpy(jbest, jtemp);
            best[0] = score[0];
            best[1] = score[1];
            best[2] = score[2];
        }
        
        return;
    }
    
    switch (mode)
    {
    case -1:
        if (ctemp[i] == '?')
            ctemp[i] = '9';
        if (jtemp[i] == '?')
            jtemp[i] = '0';
        go(i + 1, mode);
        break;
    case 0:
        if (ctemp[i] == '?' && jtemp[i] == '?')
        {
            ctemp[i] = '0';
            jtemp[i] = '1';
            go(i + 1, -1);
            ctemp[i] = '0';
            jtemp[i] = '0';
            go(i + 1, 0);
            ctemp[i] = '1';
            jtemp[i] = '0';
            go(i + 1, 1);
        }
        else if (ctemp[i] == '?')
        {
            if (jtemp[i] != '0')
            {
                ctemp[i] = jtemp[i] - 1;
                go(i + 1, -1);
            }
            ctemp[i] = jtemp[i];
            go(i + 1, 0);
            if (jtemp[i] != '9')
            {
                ctemp[i] = jtemp[i] + 1;
                go(i + 1, 1);
            }
        }
        else if (jtemp[i] == '?')
        {
            if (ctemp[i] != '0')
            {
                jtemp[i] = ctemp[i] - 1;
                go(i + 1, 1);
            }
            jtemp[i] = ctemp[i];
            go(i + 1, 0);
            if (ctemp[i] != '9')
            {
                jtemp[i] = ctemp[i] + 1;
                go(i + 1, -1);
            }
        }
        else
        {
            go(i + 1, ctemp[i] < jtemp[i] ? -1 : ctemp[i] > jtemp[i] ? 1 : 0);
        }
        break;
    case 1:
        if (ctemp[i] == '?')
            ctemp[i] = '0';
        if (jtemp[i] == '?')
            jtemp[i] = '9';
        go(i + 1, mode);
        break;
    }
}

int main()
{
    int t, x;
    
    scanf("%d ", &t);
    for (x = 1; x <= t; x++)
    {
        scanf("%s%s", c, j);
        
        best[0] = (uint64_t)-1;
        best[1] = (uint64_t)-1;
        best[2] = (uint64_t)-1;
        
        go(0, 0);
        
        printf("Case #%d: %s %s\n", x, cbest, jbest);
    }
    return 0;
}
