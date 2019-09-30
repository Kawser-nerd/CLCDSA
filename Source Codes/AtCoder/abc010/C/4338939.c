#include <stdio.h>
int checkT(int xs, int ys, int mx, int my, int xe, int ye, double lim);
double getdist(int a, int b, int c, int d);
int square(int a);

int main(void)
{
    int xs, ys, xe, ye;
    scanf("%d%d%d%d", &xs, &ys, &xe, &ye);
    int t, v;
    scanf("%d%d", &t, &v);
    double lim = t * v;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (checkT(xs, ys, x, y, xe, ye, lim))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}

int checkT(int xs, int ys, int mx, int my, int xe, int ye, double lim)
{
    double dist = getdist(xs, ys, mx, my) + getdist(mx, my, xe, ye);
    if (dist <= lim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double getdist(int a, int b, int c, int d)
{
    int xdif = a - c;
    int ydif = b - d;
    double dist = sqrt(square(xdif) + square(ydif));
    return dist;
}

int square(int a)
{
    return a * a;
} ./Main.c: In function ‘getdist’:
./Main.c:47:19: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
     double dist = sqrt(square(xdif) + square(ydif));
                   ^
./Main.c:47:19: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:47:19: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &xs, &ys, &xe, &ye);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &t, &v);
     ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &x, &y)...