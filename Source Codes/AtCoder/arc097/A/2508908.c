#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_char(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

int fact_cal(int L){
    int fact = 1;
    for(int i=1; i<=L; ++i) fact = fact * i;
    return fact;
}

int main(void){
    char s[5050];
    int K;
    scanf("%s %d",s,&K);

    char substr[K+1][strlen(s)+1];
    char a[strlen(s)],b[strlen(s)],tmp[strlen(s)];
    int count = 0;
    strcpy(b,"z");
    for(int j=0;j<strlen(s)-1;j++) strcat(b,"z");
    for(int i=0;i<K+1;i++){
        strcpy(substr[i],b);
    }

    for(int i = 0; i < strlen(s); i++){
        for(int j = i; j < strlen(s);j++){
            a[0] = '\0';
            strncpy(a,s+i,j+1-i);
            a[j+1-i]='\0';
            if(strlen(a) <= K){
                strcpy(substr[K],a);
                for(int l=1;l<K+1;l++){
                    for(int k=1;k<K+1;k++){
                        if(strcmp(substr[k-1], substr[k]) == 0){
                            strcpy(substr[k],b);
                        }
                        if(strcmp(substr[k-1], substr[k])>0){
                            strcpy(tmp, substr[k-1]);
                            strcpy(substr[k-1], substr[k]);
                            strcpy(substr[k], tmp);
                        }
                    }
                }
            }
        }
    }
    printf("%s\n",substr[K-1]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d",s,&K);
     ^