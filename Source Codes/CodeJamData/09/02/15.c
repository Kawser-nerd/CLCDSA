#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alt[100][100];
char label[100][100];
char currentl = 'a';
int H;
int W;

// dir in (y,x) diffs, north, west, east, south
int dir[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int labelit(int y, int x) {
    if (label[y][x] != 0) {
        // already labeled
        return label[y][x];
    }
    int lowx;
    int lowy;
    int lowalt = alt[y][x];

    int i;
    int j;

    for (i = 0; i < 4; i ++) {
        int newy = y + dir[i][0];
        int newx = x + dir[i][1];

        if (newy >= 0 && newx >=0 && newy < H && newx < W) {
            int newlowalt = alt[newy][newx];
            if (lowalt > newlowalt) {
                lowy = newy;
                lowx = newx;
                lowalt = newlowalt;
            }
        }
    }
    if (lowalt == alt[y][x]) {
        // this is the sink :(
        label[y][x] = currentl;
        char oldl = currentl;
        currentl ++;
        return oldl;
    }
    else {
        char oldl = labelit(lowy, lowx);
        label[y][x] = oldl;
        return oldl;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    int i;
    int j;
    int k;
    int w;
    for (i = 0; i < T; i ++) {
        scanf("%d %d", &H, &W);

        for (j = 0; j < H; j ++) {
            for (k = 0; k < W; k ++) {
                int a;
                scanf("%d", &a);
                // assigning altitue
                alt[j][k] = a;
                label[j][k] = 0;
            }
        }
        
        currentl = 'a';
        // now the map H, W is full
        for (j = 0; j < H; j ++) {
            for (k = 0; k < W; k ++) {
                labelit(j, k);
            }
        }

        // print the thing
        printf("Case #%d:\n", i + 1);

        for (j = 0; j < H; j ++) {
            for (k = 0; k < W; k ++) {
                printf("%c", label[j][k]);
                if (k != W-1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
