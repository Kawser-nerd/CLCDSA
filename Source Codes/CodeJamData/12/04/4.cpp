#include <iostream>
using namespace std;
char grid[40][40];
char newgrid[40][40];
int gcd(int a, int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    while (b) {
        int t = a%b; a = b; b = t;
    }
    return a;
}
int mex,mey,H,W,D;
int mat[3][3];
int mat2[3][3] = {
    {-1,0,0},
    {0,1,0},
    {0,0,1}
};
int mat3[3][3] = {
    {1,0,0},
    {0,-1,0},
    {0,0,1}
};
void mult(int a[3][3], int b[3][3]) {
    int c[3][3];
    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) {
        c[i][j] = 0;
        for (int k=0; k<3; k++) c[i][j] += a[i][k]*b[k][j];
    }
    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) a[i][j] = c[i][j];
}
bool isme(int x, int y) {
    int realx = x*mat[0][0] + y*mat[0][1] + mat[0][2];
    int realy = x*mat[1][0] + y*mat[1][1] + mat[1][2];
    assert(realx%2==0 && realy%2==0);
//    printf("Which is really %d %d\n",realx/2,realy/2);    
    return grid[realx/2][realy/2]=='X';    
}
bool ismirror(int x, int y) {
    int realx = x*mat[0][0] + y*mat[0][1] + mat[0][2];
    int realy = x*mat[1][0] + y*mat[1][1] + mat[1][2];    
    assert(realx%2==0 && realy%2==0);
//    printf("Which is really %d %d\n",realx/2,realy/2);
    return grid[realx/2][realy/2]=='#';
}
void reflectx(int x) {
    mat2[0][2] = 2*x;
    mult(mat,mat2);
//    printf("Reflect x\n");
}
void reflecty(int y) {
    mat3[1][2] = 2*y;
    mult(mat,mat3);    
//    printf("Reflect y\n");    
}
bool solve(int dx, int dy) {
    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) mat[i][j] = i==j?1:0;
    dx *= 2; dy *= 2;
    // double all coordinates
//    printf("I am at %d,%d\n",mex,mey);
//    printf("Trying %d,%d\n",dx/2,dy/2);
    int refx = 2*mex, refy = 2*mey;
    while ((refx+dx-2*mex)*(refx+dx-2*mex)+(refy+dy-2*mey)*(refy+dy-2*mey)<=4*D*D) {
        // travel in direction dx,dy (dx>=dy) and see what is in the square we end up in
        for (int x=1; x<dx; x+=2) {
            // are we at a grid point?
            bool grid = false;
            if ((dy*x)%dx==0 && (dy*x/dx)%2==1) {
                grid = true;
//                printf("At grid point\n");
                int y = x*dy/dx;
//                printf("Want to check mirrors at %d,%d, %d,%d and %d,%d\n",(x-1+refx)/2,(y+1+refy)/2,(x+1+refx)/2,(y+1+refy)/2,(x+1+refx)/2,(y-1+refy)/2);
                bool m1 = ismirror(x-1+refx,y+1+refy);
                bool m2 = ismirror(x+1+refx,y+1+refy);
                bool m3 = ismirror(x+1+refx,y-1+refy);                                
                // if !m2, go straight through
                if (m2) {
                    if (!m1 && !m3) {
                        // destroyed
//                        printf("Destroyed\n");
                        return false;
                    }
                    if (m1) reflecty(y+refy);
                    if (m3) reflectx(x+refx);
                }
                // we are at a grid point - up to three important mirrors
            } else {
//                printf("At vertical line\n");
                int rx = x+1;
                // ry is closest even integer to y = x*dy/dx
                int ry = 2*(int)(0.5*x*dy/dx+0.5);
//                printf("Want to check if mirror at %d,%d\n",(rx+refx)/2,(ry+refy)/2);
                if (ismirror(rx+refx,ry+refy)) {
                    reflectx(x+refx);
                }
            }
            
            // do we go over any horizontal lines moving from x to x+2?
            // ie, are there any odd integers strictly between y values
            // y goes from x*dy/dx to (x+2)*dy/dx
            
            int nextint = x*dy/dx+1;
            int prevint = ((x+2)*dy+dx-1)/dx-1;
            
            if (nextint%2==0) nextint++;
            if (prevint%2==0) prevint--;
            if (prevint==nextint) {
                int y = prevint;
//                printf("At horizontal line\n");                    
                // x = y * dx / dy
                int rx = 2*(int)(0.5*y*dx/dy+0.5);
                int ry = y+1;
//                printf("Want to check if mirror at %d,%d\n",(rx+refx)/2,(ry+refy)/2);
                if (ismirror(rx+refx,ry+refy)) {
                    reflecty(y+refy);
                }
                // we are at a horizontal line - just check mirror above
            }            
        }
//        printf("At %d,%d\n",(refx+dx)/2,(refy+dy)/2);
        if (isme(refx+dx,refy+dy)) {
//            printf("SAW MYSELF!!!\n");
            return true;
        }
        refx += dx;
        refy += dy;
    }
    return false;
}
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        scanf("%d %d %d",&H,&W,&D);
        // changing x and y, i'm too confused with (y,x)
        for (int i=0; i<H; i++) {
            scanf("%s",newgrid[i]);
            for (int j=0; j<W; j++) grid[j][i] = newgrid[i][j];
        }
        for (int i=0; i<W; i++)
        for (int j=0; j<H; j++) {
            if (grid[i][j]=='X') {
                mex=i;mey=j;
            }
        }
        // first let's assume x movement is > 0, then rotate four times and reflect
        int finalans = 0;
        for (int reflect=0; reflect<2; reflect++) {
            for (int rot=0; rot<4; rot++) {
//                for (int j=H-1; j>=0; j--) {
//                    for (int i=0; i<W; i++) {
//                        printf("%c",grid[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n");
                
                for (int x=1; x<=D; x++)
                for (int y=0; y<=x; y++) {
                    if (x*x+y*y>D*D) continue;
                    if (gcd(x,y)!=1) continue;
                    if ((x==y || y==0) && reflect==1) continue;
                    if (solve(x,y)) finalans++;
                }          
                
                // solve for this rotation
                // rotate whole grid 90 degrees about bottom right corner
                for (int i=0; i<W; i++)
                for (int j=0; j<H; j++) {
                    newgrid[H-1-j][i] = grid[i][j];
                }
                int newmex = H-1-mey, newmey = mex;
                int newW = H, newH = W;
                mex = newmex; mey = newmey; W = newW, H = newH;
                for (int i=0; i<W; i++)
                for (int j=0; j<H; j++) {
                    grid[i][j] = newgrid[i][j];
                }
            }
            // reflect
            for (int i=0; i<W; i++)
            for (int j=0; j<H; j++) {
                newgrid[i][j] = grid[W-1-i][j];
            }
            mex = W-1-mex;
            for (int i=0; i<W; i++)
            for (int j=0; j<H; j++) grid[i][j] = newgrid[i][j];
        }
        printf("Case #%d: %d\n",t,finalans);
    }
}
