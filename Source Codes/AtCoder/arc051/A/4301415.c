#include<stdio.h>
int main()
{
    int x1, y1, r;
    scanf("%d %d %d", &x1, &y1, &r);
    int x2, y2, x3, y3;
    scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
    if (x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3)
        printf("NO\n");
    else
        printf("YES\n");
    int d1, d2, d3, d4;
    d1 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
    d2 = (x2 - x1)*(x2 - x1) + (y3 - y1)*(y3 - y1);
    d3 = (x3 - x1)*(x3 - x1) + (y2 - y1)*(y2 - y1);
    d4 = (x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1);
    if (d1 <= r * r && d2 <= r * r && d3 <= r * r && d4 <= r * r)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x1, &y1, &r);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
     ^