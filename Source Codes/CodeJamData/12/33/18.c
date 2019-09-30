
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define ISSUE printf("\n\nError file %s line %d\n\n", __FILE__, __LINE__); exit(-1);

#define NB  20

#define UInt32 unsigned long int
#define UInt8 unsigned char

/*
UInt32 max(UInt32 x, UInt32 y) 
{
    if (x > y)
    {
        return x;
    }
    
    return y;
}

UInt32 min(UInt32 x, UInt32 y) 
{
    if (x < y)
    {
        return x;
    }
    
    return y;
}
*/

#define DEB 0

UInt32 FindBest(UInt32 nbBox[1024],
              UInt32 nbToy[1024],
              UInt32 typeBox[1024],
              UInt32 typeToy[1024],
              UInt32 N, UInt32 M, UInt32 indBox, UInt32 indToy, UInt32 seed)
{
    UInt32 how, left, right, i;
    UInt32 nbBoxCopy[1024];
    UInt32 nbToyCopy[1024];
    UInt32 val;
    
#if DEB
    printf("\n---> %d %d %d %d / %d %d", indBox, indToy, typeBox[indBox], typeToy[indToy], nbBox[indBox], nbToy[indToy]);
#endif
    
    if (N == indBox)
    {
        return 0;
    }

    if (M == indToy)
    {
        return 0;
    }
    
    if (nbBox[indBox] == 0)
    {
        val = FindBest(nbBox, nbToy, typeBox, typeToy, N, M, indBox + 1, indToy, seed);        
//        printf("\nReturn %lld", val);
        return val;
    }
    
    if (nbToy[indToy] == 0)
    {
        val = FindBest(nbBox, nbToy, typeBox, typeToy, N, M, indBox, indToy + 1, seed);        
 //       printf("\nReturn %lld", val);
        return val;
    }

    if (typeBox[indBox] == typeToy[indToy])
    {
        /* Advance by min */
        if (nbToy[indToy] < nbBox[indBox])
        {
            how = nbToy[indToy];
        }
        else
        {
            how = nbBox[indBox];
        }
        
        nbBox[indBox] -= how;
        nbToy[indToy] -= how;
        
#if DEB
        printf("\nAdd %lld (%lld %lld)", how, nbToy[indToy], nbBox[indBox]);
#endif
        
        val = (how + FindBest(nbBox, nbToy, typeBox, typeToy, N, M, indBox, indToy, seed));        
//        printf("\nReturn %lld", val);
        return val;
    }
    else 
    {

        for (i = 0; i < N; i++)
        {
            nbBoxCopy[i] = nbBox[i];
        }
        
        for (i = 0; i < M; i++)
        {
            nbToyCopy[i] = nbToy[i];
        }
        
            left = FindBest(nbBoxCopy, nbToyCopy, typeBox, typeToy, N, M, indBox, indToy + 1, random());

        for (i = 0; i < N; i++)
        {
            nbBoxCopy[i] = nbBox[i];
        }
        
        for (i = 0; i < M; i++)
        {
            nbToyCopy[i] = nbToy[i];
        }

            right = FindBest(nbBoxCopy, nbToyCopy, typeBox, typeToy, N, M, indBox + 1, indToy, random());        

            if (left > right)
            {
                val = left;
            }
            else 
            {
                val = right;
            }

  //      printf("\nReturn %lld", val);
        return val;
    }

    
}


void Show(UInt32 List[1024], UInt32 nb)
{
    int i;
    
    printf("List (%d)\n", nb);
    
    for (i = 0; i < nb; i++)
    {
        printf("%lld ", List[i]);
    }
    
    printf("\n\n");
}

int main()
{
	float output;
	unsigned int nbCase = 1;
	FILE* file;
    char line[1024];
    unsigned int nbSamples, i, j, k, l, m;
    char string[1024];
    UInt8 isDone, stop;

    UInt32 N, M, ans;
    UInt32 sum, seed, newans;
    UInt32 nbBox[1024];
    UInt32 nbToy[1024];
    UInt32 typeBox[1024];
    UInt32 typeToy[1024];
    
//    file = fopen("/Users/cryptouser/Downloads/A-large-practice.in", "r");
    file = fopen("input.txt", "r");
    
    if (file == NULL)
    {
        ISSUE;
    }
    
    fgets(line, 1024, file);
    
    nbSamples = atoi(line);
    
    for (i = 0; i < nbSamples; i++)
    {
        fscanf(file, "%d %d", &N, &M);

        for (j = 0; j < N; j++)
        {
            fscanf(file, "%lld", &nbBox[j]);
            fscanf(file, "%lld", &typeBox[j]);
        }
        
        fscanf(file, "\n");
        
        for (j = 0; j < M; j++)
        {
            fscanf(file, "%lld", &nbToy[j]);
            fscanf(file, "%lld", &typeToy[j]);
        }

        fscanf(file, "\n");

#if 0
        printf("\nIII\n");
        Show(nbBox, N);
        Show(typeBox, N);
        Show(nbToy, M);
        Show(typeToy, M);
#endif
        
        newans = 0;
        ans = 0;
        
        ans = FindBest(nbBox, nbToy, typeBox, typeToy, N, M, 0, 0, random());
        
        printf("Case #%d: %lld", nbCase, ans);

        
        printf("\n");
        
        nbCase++;
    }
}


