#include<stdio.h>
#include<stdlib.h>
#include <string.h>



void reset_bitmap(int* bitmap, int length)
{
    int i;

    for(i=0; i<length; i++)
        bitmap[i] = 0;
}

int check_bitmap(int *bitmap, int length)
{
    int i;

    for(i=0; i<length; i++)
        if(bitmap[i] == 0)
            return 0;

    return 1;
}

void print_bitmap(int *bitmap, int length)
{
    int i;

    for(i=0; i<length; i++)
        printf("%d", bitmap[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE* file;
    char line[1024], engines[101][101];
    int nr_cases, i, nr_engines, j, nr_queries, bitmap[101], nr_changes, k;

    //printf("File %s\n", argv[1]);
    file = fopen(argv[1], "r");
    if(!file)
        exit(1);
  
    fgets(line, 1024, file); 
    nr_cases = atoi(line);
//printf("Number of cases = %d\n", nr_cases);
    for(i=0; i<nr_cases; i++)
    {
        nr_changes = 0;
        fgets(line, 1024, file); 
        nr_engines = atoi(line);
//printf("Number of engines = %d\n", nr_engines);
        for(j=0; j<nr_engines; j++)
        {
            fgets(engines[j], 101, file); 
//printf("Engine read: \"%s\"\n", engines[j]);            
        }
        fgets(line, 1024, file); 
        nr_queries = atoi(line);
//printf("Number of queries = %d\n", nr_queries);
        reset_bitmap(bitmap, 101);
        for(j=0; j<nr_queries; j++)
        {
            fgets(line, 1024, file); 
query_again:            
//printf("Query[%d] = \"%s\"\n", j, line);
            for(k=0; k<nr_engines; k++)
            {
                if(strcmp(line, engines[k]) == 0)
                {
                    bitmap[k] = 1;
                }
                if(check_bitmap(bitmap, nr_engines))
                {
                    nr_changes++;
                    reset_bitmap(bitmap, 101);
                    goto query_again;
                }
            }
//print_bitmap(bitmap, nr_engines);
        }
//printf(">> Nr changes=%d\n", nr_changes);        
        printf("Case #%d: %d\n", (i+1), nr_changes);
    }
}
