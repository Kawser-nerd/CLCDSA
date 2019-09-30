#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_P   (10000 + 2)
//#define MAX_P   (100 + 2)
#define MAX_Q   (6)

int p, q;
int Q[MAX_Q];
int P[MAX_P];
int best[MAX_P];
char best_status[MAX_Q][MAX_P];

char data[MAX_Q];
char used[MAX_Q];
int count = 0;
int bestCost = 0xFFffFF;
int bestPerm[MAX_Q];

void perm(int level, int select)
{
    int i;

    if (level >= 0)
        data[level] = select;
    
    if (level == q - 1)
    {
        int sumLeft;
        int sumRight;
        int cost = 0;
        int j;

        // init
        for (i = 0; i <= p+1; i++)
        {
            P[i] = 1;
        }

        P[0] = 0;
        P[p+1] = 0;

        for (i = 0; i < q; i++)
        {
            // mark
            P[Q[data[i]]] = 0;

            // left
            sumLeft = 0;
            for (j = Q[data[i]] - 1; P[j] != 0; j--)
            {
                sumLeft++;
            }

            // right
            sumRight = 0;
            for (j = Q[data[i]] + 1; P[j] != 0; j++)
            {
                sumRight++;
            }

            cost += sumLeft;
            cost += sumRight;
        }

        if (cost < bestCost)
        {
            bestCost = cost;
            for (i = 0; i < q; i++)
            {
                bestPerm[i] = data[i];
            }
        }
  
        /*
        printf("%3d: ", count);
        for (i = 0; i < q; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
        */

        count++;
    }
    else
    {
        for (i = 0; i < q; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                perm(level+1, i);
                used[i] = 0;
            }
        }
    }
}


void process2()
{
    int i;

    
    count = 0;
    bestCost = 0xFFffFF;
    for (i = 0; i < q; i++)
    {
        used[i] = 0;
    }

    perm(-1, 0);

    /*
    printf("Best Cost: %d\n", bestCost);
    printf("Best Perm: ");
    for (i = 0; i < q; i++)
    {
        printf("%d ", bestPerm[i]);
    }
    printf("\n");
    */
}

int main(void)
{
    int n;
    int i, j;
    FILE *fin = stdin;
    //FILE *fin = fopen("Debug\\test.txt", "r");

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%d %d", &p, &q);
        for (j = 0; j < q; j++)
        {
            fscanf(fin, "%d", &(Q[j]));
        }

        /*
        for (j = 0; j < q; j++)
        {
            printf("%d %d\n", j, Q[j]);
        }
        */

        // process
        process2();

        // output
        printf("Case #%d: %d\n", i+1,
            bestCost);
    }
    fclose(fin);
}


/*
void process()
{
    int i, j, k;

    // init
    for (i = 0; i < MAX_P; i++)
    {
        for (j = 0; j < MAX_Q; j++)
        {
            best[i][j] = MAX_P + 1;
        }
    }

    for (i = 0; i < MAX_P; i++)
    {
        for (j = 0; j < MAX_Q; j++)
        {    
            for (k = 0; k < MAX_P; k++)
            {
                best_status[i][j][k] = 1;
            }
        }
    }

    for (i = 0; i < MAX_P; i++)
    {
        P[i] = 1;
        best[i][1] = p - 1;
    }

    for (i = 0; i <= p + 1; i++)
    {
        for (j = 1; j <= q; j++)
        {
        }
    }

    // process
    for (i = 0; i < q; i++)
    {
        for (j = 1; j < q; j++)
        {
            // j is the count of prisons
            // i is the index to start from



        }
    }

}


*/
