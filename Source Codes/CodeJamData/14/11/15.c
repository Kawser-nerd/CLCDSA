#include<stdio.h>
#include<string.h>


void main() {
    int i, j, t, k, m, n, l;
    int count;
    int min;
    int index;
    int diff;
    char used[150];
    char device[50];
    char outlet[150][50];
    int times[150][150];
    unsigned long long matrix[150][150];
    unsigned long long tmp;
    unsigned long long addtable[41];
    addtable[0] = 1;
    
    for (i = 1 ; i < 41; i++) {
        addtable[i] = addtable[i-1] * 2;  
    }
    
    scanf("%d", &t);
    for (i = 1 ; i <= t ; i++) {
        scanf("%d %d", &n, &l);
        
        for ( j = 0 ; j < n ; j++) {
            scanf("%s", &outlet[j]);
        }

        for ( j = 0 ; j < n ; j++) {
            scanf("%s", &device);
            for (m = 0 ; m < n ; m++) {
                tmp = 0;
                diff = 0;
                for ( k = 0 ; k < l ; k++) {
                    if (outlet[m][k] != device[k]) {
                        tmp += addtable[k];
                        diff++;
                    }
                }
                matrix[j][m] = tmp;
                times[j][m] = diff;
            }
        }
        
        min = -1;
        for (j = 0 ; j < n ; j++) {
            tmp = matrix[0][j];
            for (m = 0 ; m < n ; m++) {
                used[m] = 0;
            }
            used[j] = 1;
            count = 1;
            for (k = 1 ; k < n ; k++) {
                index = -1;
                for (m = 0; m < n ; m++) {
                    if (used[m] == 0 && matrix[k][m] == tmp) {
                        index = m;
                        break;
                    }      
                }
                if (index != -1) {
                    used[index] = 1; 
                    count ++;
                } else {
                    break;
                }
            }

            if (count == n) {
                if (min == -1 || min > times[0][j]) {
                    min = times[0][j];
                }
            }
        }


        printf("Case #%d: ", i);   
        if (min == -1) {
            printf("NOT POSSIBLE\n");
        } else {
            printf("%d\n", min);
        }

    }
}
