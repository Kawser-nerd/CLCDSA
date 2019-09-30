#include <stdio.h>

int main(void){
    // Your code here!
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int slot[15] = {};
    int level[15] = {};
    int Np = 15;
    int N;
    int count = 0;
    
    scanf("%d\n",&N);
    
    for (int i = 1; i <= N; i++)
    {
        int res = i;
        for(int j = 0; j < Np && i >= prime[j]; j++)
        {
            for(int k = res; k % prime[j] == 0; k /= prime[j])
            {
                slot[j]++;
            }
        }
    }
    
    int Nclass[6] = {};
    for(int i = 0; i < Np; i++)
    {
        if(slot[i] < 2)
            level[i] = 0;
        else if(slot[i] < 4)
            level[i] = 1;
        else if(slot[i] < 14)
            level[i] = 2;
        else if(slot[i] < 24)
            level[i] = 3;
        else if(slot[i] < 74)
            level[i] = 4;
        else
            level[i] = 5;
            
        Nclass[level[i]]++;
    }
    
    // 75*1*1
    count += Nclass[5];
    // 25*3*1
    count += (Nclass[5]+Nclass[4]) * (Nclass[5]+Nclass[4]+Nclass[3]+Nclass[2]+Nclass[1]-1);
    // 15*5*1
    count += (Nclass[5]+Nclass[4]+Nclass[3]) * (Nclass[5]+Nclass[4]+Nclass[3]+Nclass[2]-1);
    // 5*5*3
    count += (Nclass[5]+Nclass[4]+Nclass[3]+Nclass[2])*(Nclass[5]+Nclass[4]+Nclass[3]+Nclass[2]-1)/2 * (Nclass[5]+Nclass[4]+Nclass[3]+Nclass[2]+Nclass[1]-2);
    /*
    for(int i=0; i < Np; i++)
        printf("%d, ", slot[i]);
    printf("\n");
    for(int i=0; i < Np; i++)
        printf("%d, ", level[i]);
    printf("\n");
    for(int i=5; i >= 0; i--)
        printf("%d, ", Nclass[i]);
    printf("\n");
    */
    printf("%d\n",count);
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&N);
     ^