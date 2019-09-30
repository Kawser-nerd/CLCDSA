#include<stdio.h>
int last2(int y)
{
    if (y % 400 == 0)
        return 29;
    if (y % 100 == 0)
        return 28;
    if (y % 4 == 0)
        return 29;
    return 28;
}
int main()
{
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    if (y%m != 0)
    {
        while (y%m != 0)
        {
            m++;
            if (m >= 13)
            {
                y++;
                m = 1;
                break;
            }
        }
        if (m / 10 == 0)
            printf("%d/0%d/01\n", y, m);
        else
            printf("%d/%d/01\n", y, m);
        return 0;
    }
    int x;
    x = y / m;
    int last;
    if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
        last = 31;
    if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
        last = 30;
    if (m == 2)
    {
        last = last2(y);
    }
    int i;
    for (i = d; i <= last; i++)
    {
        if (x%i == 0)
        {
            if (m / 10 == 0)
            {
                if (i / 10 == 0)
                    printf("%d/0%d/0%d\n", y, m, i);
                else
                    printf("%d/0%d/%d\n", y, m, i);
                return 0;
            }
            else
            {
                if (i / 10 == 0)
                    printf("%d/%d/0%d\n", y, m, i);
                else
                    printf("%d/%d/%d\n", y, m, i);
                return 0;
            }
        }
    }
    m++;
    while (y%m != 0)
    {
        m++;
        if (m >= 13)
        {
            y++;
            m = 1;
        }
    }
    if (m / 10 == 0)
        printf("%d/0%d/01\n", y, m);
    else
        printf("%d/%d/01\n", y, m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d/%d/%d", &y, &m, &d);
     ^