#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

int gcd(int x, int y) {
  x=abs(x),y=abs(y);
  while(y) {
    int t=x%y;x=y;y=t;
  }
  return x;
}

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int h,w,d; scanf("%d%d%d", &h, &w, &d);
    int sY=-1,sX=-1;
    static char tbl[40][40];
    for(int y = 0; y < h; y++) {
      scanf(" %s", tbl[y]);
      for(int x = 0; x < w; x++) {
        if(tbl[y][x]=='X') sY=y, sX=x;
      }
    }
    static int vis[101][101];
    for(int y = -d; y <= d; y++) {
      for(int x = -d; x <= d; x++) {
        vis[y+d][x+d] = false;
      }
    }
    int cnt = 0;
    for(int tY = -d; tY <= d; tY++) {
      for(int tX = -d; tX <= d; tX++) {
        if(tY*tY+tX*tX > d*d) continue;
        if(tY==0 && tX==0) continue;
        int yDen = max(1,abs(tX))*2;
        int xDen = max(1,abs(tY))*2;
        int pY = tY>0 ? 1 : tY<0 ? -1 : 0;
        int pX = tX>0 ? 1 : tX<0 ? -1 : 0;
        int cy = (sY*2+1)*yDen/2;
        int cx = (sX*2+1)*xDen/2;
        int rest = max(abs(tY)*yDen, abs(tX)*xDen);
        while(true) {
          dprintf("t=(%d,%d), p=(%d/%d,%d/%d), c=(%d/%d,%d/%d), rest=%d\n",tY,tX,pY,yDen,pX,xDen,cy,yDen,cx,xDen, rest);
          int horiz =
            pY>0 ? (yDen-cy%yDen)%yDen :
            pY<0 ? cy%yDen :
            rest+1;
          int vert =
            pX>0 ? (xDen-cx%xDen)%xDen :
            pX<0 ? cx%xDen :
            rest+1;
          if(horiz==0 && vert==0) {
            int yy = pY>0 ? cy/yDen : cy/yDen-1;
            int yyR = pY>0 ? cy/yDen-1 : cy/yDen;
            int xx = pX>0 ? cx/xDen : cx/xDen-1;
            int xxR = pX>0 ? cx/xDen-1 : cx/xDen;
            if(tbl[yy][xx]!='#') {
              horiz=yDen;
              vert=xDen;
            } else if(tbl[yy][xxR]=='#') {
              if(tbl[yyR][xx]=='#') {
                pY = -pY;
                pX = -pX;
                continue;
              } else {
                pY = -pY;
                continue;
              }
            } else {
              if(tbl[yyR][xx]=='#') {
                pX = -pX;
                continue;
              } else {
                dprintf("fail.\n");
                break;
              }
            }
          }
          if(horiz==0) {
            int yy = pY>0 ? cy/yDen : cy/yDen-1;
            int xx = cx/xDen;
            if(tbl[yy][xx]=='#') {
              pY = -pY;
              continue;
            } else horiz=yDen;
          }
          if(vert==0) {
            int yy = cy/yDen;
            int xx = pX>0 ? cx/xDen : cx/xDen-1;
            if(tbl[yy][xx]=='#') {
              pX = -pX;
              continue;
            } else vert=xDen;
          }
          if(rest==0) {
            if(cy == yDen*(sY*2+1)/2 && cx == xDen*(sX*2+1)/2) {
              // succeed
              int ry = tY/gcd(tX,tY);
              int rx = tX/gcd(tX,tY);
              dprintf("success.\n");
              if(!vis[ry+d][rx+d]) {
                dprintf("added.\n");
                cnt++;
              }
              vis[ry+d][rx+d]=true;
              break;
            } else {
              dprintf("fail.\n");
              break;
            }
          }
          int aug = min(rest,min(horiz,vert));
          rest -= aug;
          cy += pY * aug;
          cx += pX * aug;
        }
      }
    }
    printf("Case #%d: %d\n", tci+1, cnt);
  }
  return 0;
}
