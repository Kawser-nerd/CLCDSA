
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define UInt32 unsigned long long
#define ISSUE printf("\n\nError file %s line %d\n\n", __FILE__, __LINE__); exit(-1);

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
            
            sum += Note[j];
            fin[j] = 0;
        }
        
        printf("Case #%d: ", nbCase);

        /* j + s * p_i */
        /* j + s * (1 - p_i) */ 
        
        /* min when equal:
         
           (\sum j + s * p_i) / nbPar = res = X + X
         
         res = 2X / par
         
         p_i = 2X / par - j / X
         
         */
        
        isDone = 0;
        nbFinalPar = nbPar;
        effSum = sum;
        
        while (isDone == 0)
        {
            isDone = 1;
            
            for (j = 0; (j < nbPar) && (isDone == 1); j++)
            {
    //            printf("\n%d %d", sum, nbPar);
    //            printf("\n%f", (2.*sum) / nbPar);
    //            printf("\n%f", ((2.*sum) / nbPar - Note[j]));
    //            printf("\n\n");
                
                if (fin[j] == 0)
                {
                    res[j] = 100 * (((1. * (sum + effSum)) / nbFinalPar - Note[j]) / sum);

//                    printf("\n%d %f %d %d %f", j, res[j], sum, Note[j], (((2.*sum) / nbFinalPar - Note[j])));
                    
                    if (res[j] < 0)
                    {
                        /* Certain */
                        res[j] = 0;
                        nbFinalPar--;
                        fin[j] = 1;
                        isDone = 0;
                        effSum -= Note[j];
                    }
                }
            }
        }
            
        for (j = 0; j < nbPar; j++)
        {        
            printf("%.6f ", res[j]);
        }
        
        printf("\n");
        
        nbCase++;
    }
}


