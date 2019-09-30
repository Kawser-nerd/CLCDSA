#include <stdio.h>

#define LIMIT 1000000007


void fact(int *fact_num, int a, int b)
{
    int i, j;
    int temp;
    
    
    for(i=a; i<=b; i++)
    {
        temp = i;
        j = 2;
        
        while(temp>1)
        {
            while(temp%j == 0)
            {
                fact_num[j]++;
                temp /= j;
            }
            
            j++;
        }
    }
}

void simpl_fact(int *fact_num, int a)
{
    int i, j;
    int temp;
    
    
    for(i=2; i<=a; i++)
    {
        temp = i;
        j = 2;
        
        while(temp>1)
        {
            while(temp%j == 0)
            {
                fact_num[j]--;
                temp /= j;
            }
            
            j++;
        }
    }
}

int main(void)
{
    int N, M;
    int i, j;
    int prime[150000];
    int prime_ctr;
    int prime_num[150000];
    int temp;
    long long p;
    
    int fact_num[150000];
    
    
    scanf("%d %d", &N, &M);
    
    /**/
    
    prime_ctr = 0;
    prime_num[0] = 0;
    temp = M;
    i = 2;
    
    
    while(temp>1)
    {
        if(temp%i == 0)
        {
            //printf("prime = %d\n", i);
            prime[prime_ctr] = i;
            
            do{
                prime_num[prime_ctr]++;
                temp /= i;
            }while(temp%i == 0);
            //printf("prime_num = %d\n", prime_num[prime_ctr]);
            
            prime_num[++prime_ctr] = 0;
        }
        
        i++;
    }
    //printf("prime_ctr = %d\n", prime_ctr);
    
    /**/
    
    for(i=0; i<150000; i++)
    {
        fact_num[i] = 0;
    }
    
    
    for(i=0; i<prime_ctr; i++)
    {
        fact(fact_num, N, prime_num[i]+N-1);
        simpl_fact(fact_num, prime_num[i]);
    }
    //system("pause");
    
    
    p = 1;
    
    
    for(i=2; i<150000; i++)
    {
        for(j=0; j<fact_num[i]; j++)
        {
            p = (p*i)%LIMIT;
        }
    }
    
    
    /**/

    printf("%lld\n", p);
    
    //system("pause");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:67:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^