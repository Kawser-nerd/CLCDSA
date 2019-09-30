//#pragma comment(linker, "/stack:128000000");
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 1

typedef unsigned __int8   U8;
typedef unsigned __int16  U16;
typedef unsigned __int32  U32;
typedef unsigned __int64  U64;
typedef   signed __int8   S8;
typedef   signed __int16  S16;
typedef   signed __int32  S32;
typedef   signed __int64  S64;
//typedef unsigned __int128 U128;
//typedef   signed __int128 S128;


char isprime(U64 n);
void base(U8 b, U64 n, char* result);

#endif

#define MAX 50

char data[MAX][MAX];
int n;

int iscomplete()
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
            if ('1' == data[i][j])
                return 0;
    }
    return 1;
}

int greedy()
{
    int i, j;
    int min = 0;
    int r = n;
    int c = n;
    int k;

    for (i = 0; i < r; i++)
    {
        int found = -1;
        // find the first row that ok
        for (j = i; j < r; j++)
        {
            int ok = 1;
            // is this row correct for i
            for (k = i + 1; k < c; k++)
            {
                if ('1' == data[j][k])
                {
                    ok = 0;
                    break; // for k
                }
            }

            if (ok)
            {
                found = j;
                break; // for j
            }
        }

        // now found is the correct item
        if (-1 == found)
        {
            printf("error\n");
        }
        else
        {
            min += found - i;

            for (j = found; j > i; j--)
            {
            // swap row [j] and [j-1]
            char buf[BUFSIZ];
            strcpy(buf, data[j]);
            strcpy(data[j], data[j-1]);
            strcpy(data[j-1], buf);
            }
        }
    }

    // printf("min = %d\n", min);
    return min;
}

// GOOGLE CODE JAM MAIN
int main(void)
{
    int t;
    int i;
    int j;
    int result;

    //freopen("input1.txt", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d\n", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%s\n", &(data[j]));
        }

        result = greedy();

        //printf("is complete = %d\n", iscomplete());

        printf("Case #%d: %d\n", i+1, result);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

/*

Programming Technique:
Todo: prime, sieve

sorting an array of integer, please note that we can't use with float/double
qsort(a, 4, sizeof(int), memcmp);

*/


#if 1


char isprime(U64 n)
{
    U64 i;
    if (1 >= n) return 0;
    for (i = 2; i * i <= n; i++)
        if (0 == n % 2)
            return 0;
    return 1;
}

void base(U8 b, U64 n, char* result)
{
    char c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    U8 r;
    U64 i = 0;

    if (1 >= b) { result[0] = '\0'; return; }
    
    while (n > 0)
    {
        r = n % b;
        n /= b;
        result[i] = c[r];
        i++;
    }
    result[i] = '\0';
    strrev(result);
}




#endif