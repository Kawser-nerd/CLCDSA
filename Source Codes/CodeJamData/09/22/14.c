#include <stdio.h>

char num[32];

void swap(char *a, char *b)
{
    char t;
    
    t = *a;
    *a = *b;
    *b = t;
}

void reverse(char *a, int len)
{
    int i;
    
    for(i=0; i<len/2; i++)
    {
        swap(&a[i], &a[len-i-1]);
    }
}

void increase(void)
{
    int i, j, len;
    
    for(len=0; num[len]; len++) ;
    
    for(i=len-2; i>=0; i--)
    {
        for(j=len-1; j>i; j--)
        {
            if(num[i]<num[j])
            {
                swap(&num[i], &num[j]);
                reverse(&num[i+1], len-i-1);     
                return;
            }
        }
    }
    
}

int main(void)
{
    int T, i;
    
    scanf("%d\n", &T);
    
    for(i=1; i<=T; i++)
    {
        // Input number and add a leading zero
        gets(num+1);
        num[0]='0';
        
        increase();
        
        printf("Case #%d: %s\n", i, (num[0]=='0') ? num+1 : num);
    }
    
    return 0;
}
