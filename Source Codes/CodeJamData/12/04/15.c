#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int T, H, W, D, tc, p, c, x, y, sx, sy;
    int ts, tx, ty, dx, dy, qx, qy;
    char map[30][30];
    scanf("%d", &T);
    for(tc=1; tc<=T; ++tc) {
        scanf("%d %d %d\n", &H, &W, &D);
        for(y=0; y<H; ++y) {
            for(x=0; x<W; ++x) {
                map[x][y] = getchar();
                if(map[x][y] == 'X') {
                    sx = x;
                    sy = y;
                }
            }
            if(getchar() != '\n') {
                if(!feof(stdin)) {
                    fprintf(stderr, "Input error\n");
                    exit(1);
                }
            }
        }
        c = 0;
        // branch by quarter-plane
        for(p=0; p<4; ++p) {
            for(y=1; y<D; ++y) {
                for(x=1; x<D; ++x) {
                    if(x*x + y*y <= D*D) {
                        dx = 2 * (p / 2) - 1;
                        dy = 2 * (p % 2) - 1;
                        tx = sx; ty = sy;
                        qx = y;  qy = x;
                        for(ts=2*x*y-1; ts>=0; --ts) {
                            ++qx; ++qy;
                            if(qx == 2 * y) {
                                qx = 0;
                                if(qy == 2 * x) {
                                    qy = 0;
                                    // diagonal step
                                    if(map[tx+dx][ty+dy] == '#') {
                                        if(map[tx+dx][ty] == '#') {
                                            dx = -dx;
                                            if(map[tx][ty+dy] == '#') {
                                                dy = -dy;   // diagonal reflection
                                            } else {
                                                ty += dy;   // horizontal reflection
                                            }
                                        } else {
                                            tx += dx;
                                            if(map[tx][ty+dy] == '#') {
                                                dy = -dy;   // vertical reflection
                                            } else {
                                                break;      // light is destroyed
                                            }
                                        }
                                    } else {
                                        tx += dx; ty += dy; // no reflection
                                    }
                                } else {
                                    // horizontal step
                                    if(map[tx+dx][ty] == '#') {
                                        dx = -dx;   // horizontal reflection
                                    } else {
                                        tx += dx;   // no reflection
                                    }
                                }
                            } else {
                                if(qy == 2 * x) {
                                    qy = 0;
                                    // vertical step
                                    if(map[tx][ty+dy] == '#') {
                                        dy = -dy;   // vertical reflection
                                    } else {
                                        ty += dy;   // no reflection
                                    }
                                } else {
                                    if(qx == y && qy == x) {
                                        // approaching the centre of a square
                                        if(map[tx][ty] == 'X') {
                                            break;  // light hits us
                                        }
                                    }
                                }
                            }
                        }
                        if(ts == 0 && qx == y && qy == x) {
                            // we see ourselves at (+-x, +-y)
                            ++c;
                            //printf("(%d, %d)\n", (2*(p/2)-1)*x, (2*(p%2)-1)*y);
                        }
                    }
                }
            }
        }
        // we still have to consider pure-horizontal / pure-vertical images
        for(p=0; p<4; ++p) {
            dx = p / 2 + p % 2 - 1;
            dy = p / 2 - p % 2;
            tx = sx; ty = sy;
            ts = D + 1;
            do {
                tx += dx;
                ty += dy;
                ts -= 2;
            } while(map[tx][ty] != '#' && ts >= 0);
            if(ts >= 0) ++c;
            //if(ts >= 0) printf("(%d, %d)\n", 2*(tx-sx)-dx, 2*(ty-sy)-dy);
        }
        printf("Case #%d: %d\n", tc, c);
    }
    return 0;
}

