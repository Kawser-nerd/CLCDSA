#include <stdio.h>
#include <string.h>

char S[50000];
char Srle[50000];
int k;
int size;
int perm[16];
int cSum;
int minRLE;

int genPerm(int indice)
{

    if(indice < k)
    {
        //printf("Indice: %i\n", indice);
        for(int i = 0; i < k; i++)
        {
            perm[indice] = i;
            genPerm(indice+1);
        }
    }
    else
    {
        //printf("Indice: %i  ", indice);

        int sum = 0;
        //printf("Perm:");
        for(int i = 0; i < k; i++)
        {
            //printf("%i ", perm[i]);
            sum |= (1 << perm[i]);
        }
        if(sum == cSum)
        {
            //printf("sum: %i  ", cSum);
            for(int i = 0; i < size; i += k)
            {
                for(int j = 0; j < k; j++)
                {
                    Srle[i+j] = S[i+perm[j]];
                    //printf("%c", Srle[i+j]);
                }
            }
            //printf("  ");
            int rle = 1;
            char cAt = Srle[0];
            for(int i = 1; i < size; i++)
            {
                if(Srle[i] != cAt)
                {
                    cAt = Srle[i];
                    rle++;
                }
            }
            if(rle < minRLE)
                minRLE = rle;
        }
        //printf("\n");
    }
}


int main()
{
    int nCases;

    scanf("%i", &nCases);
    for(int c = 1; c <= nCases; c++)
    {
        scanf("%i", &k);
        scanf("%s", S);
        size = strlen(S);
        cSum = 0;
        for(int i = 0; i < k; i++)
        {
            cSum |= (1 << i);
        }
        //printf("cSum: %i\n", cSum);
        minRLE = size;
        genPerm(0);
//        for(int i = 0; i < k; i++)
//        {
//            printf("%i ", perm[i]);
//        }
//        printf("\n");
//        for(int i = 0; i < size; i++)
//        {
//            printf("%c", S[i]);
//        }
//        printf("\n");
        printf("Case #%i: %i\n", c, minRLE);
    }
}
