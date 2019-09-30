#include <stdio.h>
#include <stdlib.h>

#define P 1000000007


int ctr[26], index[26], index_num = 0;

long long int accum = 0;


void trace(long long int product, int level, int level_num, int pos)
{
    int i;
    
    
    if(level == level_num)
    {
        accum += product;
        accum %= P;
    }
    else
    {
        for(i=pos; i<index_num && level_num-level<=index_num-i; i++)
        {
            trace((product*ctr[index[i]])%P, level+1, level_num, i+1);
        }
    }
}

int main(void)
{
    int N;
    char *S;
    int i;
    
    
    scanf("%d", &N);
    
    S = (char*)malloc(sizeof(char)*(N+1));
    
    scanf("%s", S);
    
    
    for(i=0; i<26; i++)
    {
        ctr[i] = 0;
    }
    
    for(i=0; i<N; i++)
    {
        switch(S[i])
        {
            case 'a':
                ctr[0]++;
                break;
            case 'b':
                ctr[1]++;
                break;
            case 'c':
                ctr[2]++;
                break;
            case 'd':
                ctr[3]++;
                break;
            case 'e':
                ctr[4]++;
                break;
            case 'f':
                ctr[5]++;
                break;
            case 'g':
                ctr[6]++;
                break;
            case 'h':
                ctr[7]++;
                break;
            case 'i':
                ctr[8]++;
                break;
            case 'j':
                ctr[9]++;
                break;
            case 'k':
                ctr[10]++;
                break;
            case 'l':
                ctr[11]++;
                break;
            case 'm':
                ctr[12]++;
                break;
            case 'n':
                ctr[13]++;
                break;
            case 'o':
                ctr[14]++;
                break;
            case 'p':
                ctr[15]++;
                break;
            case 'q':
                ctr[16]++;
                break;
            case 'r':
                ctr[17]++;
                break;
            case 's':
                ctr[18]++;
                break;
            case 't':
                ctr[19]++;
                break;
            case 'u':
                ctr[20]++;
                break;
            case 'v':
                ctr[21]++;
                break;
            case 'w':
                ctr[22]++;
                break;
            case 'x':
                ctr[23]++;
                break;
            case 'y':
                ctr[24]++;
                break;
            case 'z':
                ctr[25]++;
                break;
        }
    }
    
    for(i=0; i<26; i++)
    {
        if(ctr[i] > 0)
        {
            index[index_num++] = i;
        }
    }
    
    
    for(i=1; i<=index_num; i++)
    {
        trace(1, 0, i, 0);
    }
    
    
    printf("%lld\n", accum);
        
        
    free(S);

    //system("pause");
    
    return 0;
} ./Main.c:7:14: warning: built-in function ‘index’ declared as non-function
 int ctr[26], index[26], index_num = 0;
              ^
./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^