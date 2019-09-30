#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1000

int min_method(int Num, char *str){
    int min = N;
    int count;
    char CHEAT[16][3]={"AA", "AB", "AX", "AY", "BA", "BB", "BX", "BY", "XA", "XB", "XX", "XY", "YA", "YB", "YX", "YY"};
    char L[3], R[3];

    for(int i = 0; i < 15; i++){
        for(int j = i+1; j < 16; j++){
            strcpy(L, CHEAT[i]);
            strcpy(R, CHEAT[j]);

            count = 0;
    
            for(int k = 0; k < Num; k++){
                if (strncmp(&str[k], L, 2) == 0 || strncmp(&str[k], R, 2) == 0){ 
                    k++;
                    count++;
                }else{
                    count++;
                }
            }

            if(count < min) min = count;
        }
    }   

return min;
}

int main(){
    int Num;
    char str[N];
    memset(str, '\0', sizeof(str));
    scanf("%d%s", &Num, str);

    printf("%d\n", min_method(Num, str));

return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s", &Num, str);
     ^