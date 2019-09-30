#include <stdio.h>

int x1, y1, r;
int x2, y2, x3, y3;

int dsqr(int x, int y)
{
    return x * x + y * y;
}

int check(void)
{
    if (dsqr((x2 - x1), (y2 - y1)) > r * r) return 0;
    if (dsqr((x2 - x1), (y3 - y1)) > r * r) return 0;
    if (dsqr((x3 - x1), (y2 - y1)) > r * r) return 0;
    if (dsqr((x3 - x1), (y3 - y1)) > r * r) return 0;
    return 1;
}

int main(void)
{
    scanf("%d %d %d", &x1, &y1, &r);
    scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
    if (x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3){
        puts("NO");
        puts("YES");
    }
    else if (check()){
        puts("YES");
        puts("NO");
    }
    else {
        puts("YES");
        puts("YES");
    }

    return 0;
} ./Main.c:3:9: warning: built-in function ‘y1’ declared as non-function
 int x1, y1, r;
         ^
./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x1, &y1, &r);
     ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
     ^