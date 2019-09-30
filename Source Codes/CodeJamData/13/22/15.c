#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_DIAMONDS 20

#define MAX_DIM   (MAX_DIAMONDS*2)
#define MAX_DIM_Y (MAX_DIAMONDS/2)

void drop_diamond(unsigned diamond_map[MAX_DIM][MAX_DIM_Y]) {
    unsigned x = MAX_DIAMONDS;
    unsigned y = MAX_DIAMONDS/2;
    int direction;
    while(1) {
        if (y == 0) break;
        assert(y>1);
        if (!diamond_map[x][y-2]) {
            y -= 2;
            continue;
        }
        if (diamond_map[x+1][y-1] && diamond_map[x-1][y-1]) break;
        if (diamond_map[x+1][y-1]) {
            direction = -1;
        } else if (diamond_map[x-1][y-1]) {
            direction = 1;
        } else {
            direction = (rand()&2)-1;
        }
        assert((direction > 0) || x > 2);
        if (diamond_map[x+(2*direction)][y-2]) {
            x += direction;
            y -= 1;
            break;
        }
        x += 2*direction;
        y -= 2;
    }
    diamond_map[x][y]++;
}


void run_sim(unsigned num_diamonds, unsigned num_iters) {
    unsigned run_map[MAX_DIM][MAX_DIM_Y];
    unsigned long long results[MAX_DIM][MAX_DIM_Y];
    memset(results,0,sizeof(results));
    for (unsigned i = 0; i < num_iters; ++i) {
        memset(run_map,0,sizeof(run_map));
        for (unsigned j = 0; j < num_diamonds; ++j) {
            drop_diamond(run_map);
        }
        for (unsigned x = 0; x <MAX_DIM; ++x) {
            for (unsigned y = 0; y <MAX_DIM_Y; ++y) {
                results[x][y] += run_map[x][y];
            }
        }
    }
    for (int y = 0; y < MAX_DIM_Y ; ++y) {
        printf("[");
        for (unsigned x = 0; x < MAX_DIM; ++x) {
            printf("%llu,",results[x][y]);
        }
        printf("],\n");
    }
}


int main() {
    printf("{\n");
    for (unsigned i = 0; i <= MAX_DIAMONDS; ++i) {
        printf("%u:[",i);
        run_sim(i,100000000);
        printf("],\n");
    }
    printf("}\n");
}

