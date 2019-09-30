#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int numOfDigits(int x)
{
    return (int)log10(x) + 1;
}

bool isIn(int elem, int array[], int array_size)
{
    for (int i = 0; i < array_size; i++)
        if (array[i] == elem)
            return true;
    return false;
}

int recycled_m(int a, int b, int n)
{
    int n_digits = numOfDigits(n),
        n_n = (int)pow(10, n_digits - 1),
        count = 0, uniq[8] = {}, uniq_size = 0, m = n;
    for (int i = 1; i < n_digits; i++) {
        m = m % 10 * n_n + m / 10;
        if (n < m && m <= b && n_digits == numOfDigits(m) && !isIn(m, uniq, uniq_size)) {
            count++;
            uniq[uniq_size++] = m;
        }
    }
    return count;
}

int main()
{
    FILE *inFile = fopen("c.in", "r");
    FILE *outFile = fopen("c.out", "w");
    int caseAmount;
    fscanf(inFile, "%d", &caseAmount);
    for (int caseNum = 1; caseNum <= caseAmount; caseNum++) {
        int a, b, result = 0;
        fscanf(inFile, "%d%d", &a, &b);
        for (int n = a; n <= b; n++)
            result += recycled_m(a, b, n);
        fprintf(outFile, "Case #%d: %d\n", caseNum, result);
    }
    return 0;
}
