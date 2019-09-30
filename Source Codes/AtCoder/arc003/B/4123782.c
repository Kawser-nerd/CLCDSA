#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUMBER 100+1
#define MAX_WORD_LENGTH 20+1

void Exchange(char str_array[][MAX_WORD_LENGTH], int *N, int index[]){
    char inversecopy[MAX_NUMBER][MAX_WORD_LENGTH];
    memset(inversecopy, '\0', sizeof(inversecopy));

    for(int i = 0; i < *N; i++){
        for(int j = 0; j < strlen(str_array[i]); j++){
            inversecopy[i][j] = str_array[i][strlen(str_array[i])-j-1];
        }   
    }   
    
    int num_temp;
    char str_temp[MAX_WORD_LENGTH];
    for(int i = 0; i < *N; i++){
        for(int j = i + 1; j < *N; j++){
            if(strcmp(inversecopy[i], inversecopy[j]) > 0){ 
                num_temp = index[i];
                index[i] = index[j];
                index[j] = num_temp;
                strcpy(str_temp, inversecopy[i]);
                strcpy(inversecopy[i], inversecopy[j]);
                strcpy(inversecopy[j], str_temp);
            }   
        }   
    }   
return;
}

int main(){
    int Num = 0;
    char Words[MAX_NUMBER][MAX_WORD_LENGTH];
    memset(Words, '\0', sizeof(Words));

    scanf("%d", &Num);
    for(int i = 0; i < Num; i++){
        scanf("%s", Words[i]);
    }   

    int correspond[MAX_NUMBER];
    for(int i = 0; i < MAX_NUMBER; i++){
        if(i < Num){correspond[i] = i;}else{correspond[i] = MAX_NUMBER+1;}
    }   
    
    Exchange(Words, &Num, correspond);

    for(int i = 0; i < Num; i++){
        printf("%s\n", Words[correspond[i]]);
    }   
return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Num);
     ^
./Main.c:42:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", Words[i]);
         ^