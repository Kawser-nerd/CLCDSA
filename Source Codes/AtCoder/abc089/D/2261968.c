#include<stdio.h>

typedef struct{
    int x;
    int y;
} point;

point num2point[100000];
int point2num[400][400];
int cost[100000];

int h, w, d;
int q;
int l, r;

void init();
void test();
void calc();
int diff_abs(int a, int b);

int main()
{
    int i;

    init();

    for (i = 0; i < q; i++) {
        scanf("%d %d\n", &l, &r);
        printf("%d\n", cost[r]-cost[l]);
    }

    return 0;
}

void init()
{
    int i, j;
    scanf("%d %d %d\n", &h, &w, &d);

    for(i = 0; i < h; i++) for(j = 0; j < w; j++){
        scanf("%d", &point2num[i][j]);
        num2point[point2num[i][j]].x = i;
        num2point[point2num[i][j]].y = j;
    }

    scanf("%d\n", &q);

    calc();
}

void calc()
{
    int i;
    int x1, x2;
    int y1, y2;

    for (i = 1; i <= d; i++)
        cost[i] = 0;

    for (i = d+1; i <= h*w; i++){
        x1 = num2point[i].x;
        x2 = num2point[i-d].x;
        y1 = num2point[i].y;
        y2 = num2point[i-d].y;
        cost[i] = cost[i-d] 
            + diff_abs(x1, x2) + diff_abs(y1, y2);
    }
}

int diff_abs(int a, int b)
{
    return a > b ? a - b : b - a;
} ./Main.c: In function ‘main’:
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d\n", &l, &r);
         ^
./Main.c: In function ‘init’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d\n", &h, &w, &d);
     ^
./Main.c:41:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &point2num[i][j]);
         ^
./Main.c:46:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &q);
     ^