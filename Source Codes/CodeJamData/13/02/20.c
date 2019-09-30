#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int checkpattern(int lawn[100][100], int n, int m) {
    int i, j;
    for(i = 0; i < n ; i ++ ) {
        for(j = 0; j < m; j ++) {
            int value = lawn[i][j] ;
            int k = 0;
            int her = 1;
            int vet = 1;
            for(k = 0; k < m ; k ++ ) {
                if(lawn[i][k] > value) {
                    break;
                }
            }
            if(k != m) {
                her = 0;
                for(k = 0; k < n ; k ++ ) {
                    if(lawn[k][j] > value) {
                        break;
                    }
                } 
                if(k != n) return 0;
            }
        }
    }
    return 1;
}



int main() {
    char* filename = "test.in";
    int numCase =0;
    
    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d\n", &numCase);

    int i,j,k;
    int lawn[100][100];
    for(i = 0; i < numCase; i ++ ) {
        int n, m;
        fscanf(fin, "%d %d", &n, &m);

        for(j = 0; j < n; j ++ ) {
            for(k = 0 ; k < m; k ++ ) {
                fscanf(fin, "%d", &lawn[j][k]);
            }
        }
        /*
        for(j = 0; j < n; j ++ ) {
            for(k = 0 ; k < m; k ++ ) {
                printf("%d ", lawn[j][k]);
            }
            printf("\n");
        }*/

        
        int ret = checkpattern(lawn, n, m);
        if(ret == 0) {
            printf("Case #%d: NO\n", i +1);
        }
        else {
            printf("Case #%d: YES\n", i +1);
        }
    }


    return 0;
}
