#include <stdio.h>

#define true 1
#define false 0

typedef unsigned char bool;

int vet[123456];

int result1(int n)
{
    int i;
    int sum = 0;
    
    for(i = 1; i < n; i++)
        if(vet[i] < vet[i-1])
            sum += (vet[i-1]-vet[i]);
        
    return sum;
}

int result2(int n)
{
    int i;
    int max, sum = 0;
    
    for(i = 1, max = 0; i < n; i++)
        if((vet[i-1]-vet[i]) > max)
            max = (vet[i-1]-vet[i]);
    
    for(i = 0; i < n-1; i++)
        if(vet[i] <= max)
            sum += vet[i];
        else
            sum += max;
        
    return sum;
}

int main()
{
    int T, cont = 0;
    
    scanf("%d\n", &T);
    while(T--)
    {
        int n, r1, r2;
        int i;
        
        scanf("%d\n", &n);
        
        for(i = 0; i < n; i++)
            scanf("%d ", &vet[i]);
        
        r1 = result1(n);
        
        r2 = result2(n);
        
        printf("Case #%d: %d %d\n", ++cont, r1, r2);
    }
    
return 0;
}
