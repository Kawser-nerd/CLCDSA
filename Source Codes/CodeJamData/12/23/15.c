
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define UInt32 unsigned long long
#define ISSUE printf("\n\nError file %s line %d\n\n", __FILE__, __LINE__); exit(-1);

#define NB  20

unsigned int Find(unsigned int le[NB])
{
    long int i, j, msum;
    long int* sum;
    long int left, right, stop;
    
    sum = malloc((1 << 20)*sizeof(long long int) );
    
    for (i = 0; i < (1 << 20); i++)
//    for (i = 0; i < 10; i++)
    {
        msum = 0;
        
        for (j = 0; j < NB; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                msum += le[j];
//                printf("\n-> %d %d %d / %d", msum, i, 1 << j, i & (1 << j));
            }
        }

        sum[i] = msum;
//        printf("\n%d %d", i, sum[i]);
    }
    
//    exit(-1);
    
    stop = 0;
    
    for (i = 0; (i < (1 << 20)) && (stop == 0); i++)
    {
        for (j = 0; (j < (1 << 20)) && (stop == 0); j++)
        {
            if ((sum[i] == sum[j]) && (i != j))
            {
                left = i;
                right = j;
                stop = 1;
//                printf("\n%d %d %d %d", i, j, sum[i], sum[j]);
            }
            
        }
    }

//    printf("\n%d %d", left, right);
    
    if (stop == 0)
    {
        printf("Impossible");
    }
    else 
    {
        i = left;
        printf("\n");
            
        for (j = 0; j < NB; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                printf("%d ", le[j]);
            }
        }
        
        printf("\n");
        i = right;
        
        for (j = 0; j < NB; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                printf("%d ", le[j]);
            }
        }
    }
}


int main()
{
	float output;
	unsigned int nbCase = 1;
	FILE* file;
    char line[1024];
    unsigned int nbSamples, i, j, k, l;
    char string[1024];
    
    unsigned int nbPar, nbFinalPar, sum, effSum;
    unsigned int Note[1024];
    double result;
    double res[256];
    int fin[256];
    int isDone;
    
    
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
        fscanf(file, "%d", &nbPar);

        sum = 0;
        
        for (j = 0; j < nbPar; j++)
        {
            fscanf(file, "%d\n", &Note[j]);
//            printf("\n%d", Note[j]);
        }
        
        printf("Case #%d: ", nbCase);

        Find(Note);
        
        printf("\n");
        
        nbCase++;
    }
}


