#include <stdio.h>


    int cflag[10010];
int answer(int g[], int v[], int r, int n, int a)
{
    int min, v2, p, d;

    int vl1, vl0, vr0, vr1;

    if (r >= n) return -1;

    if (a == v[r]) {
//        printf("Root = %d; V = %d; min = %d\n", r, a, 0);
        return 0;
    }

    if (r >= ((n - 1) / 2)) {
  //      printf("Root = %d; V = %d; min = %d\n", r, a, -1);
        return -1;
    }

    vl0 = vl1 = -1;
    vr0 = vr1 = -1;

    vl0 = answer(g, v, 2 * r + 1, n , 0);
    vl1 = answer(g, v, 2 * r + 1, n , 1);

    vr0 = answer(g, v, 2 * r + 2, n , 0);
    vr1 = answer(g, v, 2 * r + 2, n , 1);

    min = -1;
    d = 0;
    if (g[r] == 0 || cflag[r] == 1) {
        if (g[r] == 1) d = 1;
        if (a == 1) {
            if (vl1 >= 0 && (min == -1 || (vl1 + d) < min)) min = vl1 + d;
            if (vr1 >= 0 && (min == -1 || (d + vr1) < min)) min = vr1 + d;
        }
        else if (vl0 >= 0 && vr0 >= 0) {
            if (min == -1 || (vr0 + vl0 + d) < min) min = vr0 + vl0 + d;
        }
    }

    d = 0;
    if (g[r] == 1 || cflag[r] == 1) {
        if (g[r] == 0) d = 1;
        if (a == 0) {
            if (vl0 >= 0 && (min == -1 || (vl0 +d) < min)) min = vl0 + d;
            if (vr0 >= 0 && (min == -1 || (vr0 +d) < min)) min = vr0 + d;
        }
        else if (vl1 >= 0 && vr1 >= 0) {
            if (min == -1 || (vr1 + vl1+d) < min) min = vr1 + vl1+d;
        }
    }

  //  printf("Root = %d; V = %d; min = %d\n", r, a, min);

    return min;
}
int main(char **argv, int argc)
{
    int N, M, V,i,j,k,p, a, v1, v2;
    int gates[10010];
    int values[10010];

    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("Case #%d: ", i);
        scanf("%d%d", &M, &V);

        for (j = 0; j < (M - 1) / 2; j ++) {
            scanf("%d%d", &gates[j], &cflag[j]);
            values[j] = -1;
        }

        k = j;

        for (j = 0; j < (M + 1) / 2; j ++)
            scanf("%d", &values[k + j]);

        j = k + j - 2;
        for (; j > 0; j -= 2) {
           p = j / 2;
           v1 = values[j];
           v2 = values[j + 1];

           if (gates[p] == 0) {
               values[p] = (v1 || v2);
           }
           else {
               values[p] = (v1 && v2);
           }
        }

        a = answer(gates, values, 0, M, V);
        if (a == -1) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", a);
        }
    }

    return 0;
}
