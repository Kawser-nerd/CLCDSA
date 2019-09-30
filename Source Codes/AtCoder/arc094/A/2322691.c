#include <stdio.h>

int a[3];

void detect(int *max, int *min)
{
    int i;
    *max = 0;
    *min = 0;
    for (i = 1; i < 3; i++)
        if (a[*max] < a[i]) *max = i;
    for (i = 1; i < 3; i++)
        if (a[*min] > a[i]) *min = i;
}

int other(int max, int min)
{
    int res;
    for (res = 0; res < 3; res++)
        if (res != max && res != min) break;
    return res;
}

int main()
{
    int max;
    int min;
    int ans;

    scanf("%d %d %d", a, a+1, a+2);

    ans = 0;
    while (1) {
        detect(&max, &min);
        if (a[max] - a[min] <= 1) break;
        a[min] += 2;
        ans++;
    } 

    detect(&max, &min);
    if (a[max] == a[min]) printf("%d\n", ans);
    else if(a[min] == a[other(max, min)])
        printf("%d\n", ans+1);
    else printf("%d\n", ans+2);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", a, a+1, a+2);
     ^