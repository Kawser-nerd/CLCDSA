#include <stdio.h>
int main(void){
    int alf[26];
    for(int i=0;i<26;i++)
    {
        alf[i] = 0;
    }
    while(1)
    {
        char c = getchar();
        if(c < 'a' || c > 'z')
        {
            break;
        }
        int tmp = c - 'a';
        alf[tmp]++;
    }
    
    for(int i=0;i<26;i++)
    {
        if(alf[i]%2)
        {
            puts("No");
            return 0;
        }
    }
    
    puts("Yes");
    return 0;
}