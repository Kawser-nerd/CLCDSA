#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int exp_table[50];
long long nr_uglies;

int is_ugly(long long number)
{
    if((number % 2) == 0)
        return 1;
    if((number % 3) == 0)
        return 1;
    if((number % 5) == 0)
        return 1;
    if((number % 7) == 0)
        return 1;
    return 0;
}

void insert_ex(char *line, int index, int length)
{
    long long total, cur_nr;
    int i;
    long long mul;
    if(index == length - 1) 
    {
        //printf("Process!\n");
        total = 0;
        cur_nr = (long long)(line[0] - '0');
        mul = 1;
        for(i=1; i<length - 1; i++)
        {
            if(exp_table[i] == 0) 
            {
                cur_nr *= (long long)10;
                cur_nr += (long long)(line[i] - '0');
            }
            
            if(exp_table[i] == 1) 
            {
                total += mul * cur_nr;
                cur_nr = (long long)(line[i] - '0');
                mul = 1;
            }
            
            if(exp_table[i] == 2) 
            {
                total += mul * cur_nr;
                cur_nr = (long long)(line[i] - '0');
                mul = -1;
            }
        }
        total += mul * cur_nr;
//printf("==> Line: %s\nExp table:", line);        
//for(i=1; i<length; i++)
//   printf("%d ", exp_table[i]);
//printf("\nTotal: %lld\n\n\n", total);   
        if(is_ugly(total))
            nr_uglies++; 
    }
    else
    {
        exp_table[index] = 0;
        insert_ex(line, index+1, length);
        exp_table[index] = 1;
        insert_ex(line, index+1, length);
        exp_table[index] = 2;
        insert_ex(line, index+1, length);
    }
}

int main(int argc, char* argv[])
{
    FILE* file;
    char line[1024];
    int case_nr, nr_cases;

    file = fopen(argv[1], "r");
    if(!file)
        exit(1);
  
    fgets(line, 1024, file); 
    nr_cases = atoi(line);
    for(case_nr=1; case_nr<=nr_cases; case_nr++)
    {
        fgets(line, 1024, file); 
//printf("Line: %s, %d\n", line, strlen(line));
        nr_uglies = 0;
        insert_ex(line, 1, strlen(line));
        printf("Case #%d: %lld\n", case_nr, nr_uglies);
    }
}
