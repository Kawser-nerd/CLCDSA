#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_char(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}
int main(void){
    char s[5050];
    int K;
    scanf("%s %d",s,&K);

    char substr[K+1][strlen(s)+1];
    char a[strlen(s)],b[K+1],tmp[K+1];
    int count = 0;
    strcpy(b,"z");
    for(int j=0;j<K;j++) strcat(b,"z");
    for(int i=0;i<K;i++){
        strcpy(substr[i],b);
    }
    a[0] = '\0';
    for(int i = 0; i < strlen(s); i++){
        for(int j = i; j < strlen(s);j++){
            if(j+1-i <= K){
                strncpy(a,s+i,j+1-i);
                a[j+1-i]='\0';
                strcpy(substr[K],a);
                if(strcmp(substr[K-1],substr[K])>=0){
                    for(int l=0;l<K;l++){
                            if(strcmp(substr[l], substr[K]) == 0){
                                strcpy(substr[K],b);
                            }
                    }
                    qsort((void *)substr,K+1,sizeof(substr[0]),compare_char);
                }
            }
        }
    }
    printf("%s\n",substr[K-1]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d",s,&K);
     ^