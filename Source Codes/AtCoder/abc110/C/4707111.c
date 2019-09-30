#include <stdio.h>
#include <math.h>
#include <string.h>
long long int i,j;

int main(void){
    char s[200100],t[200100];
    scanf("%s %s",s,t);
    int n=strlen(s);
    int r[26]={0},R[26]={0};
    for(i=0;i<n;i++){
        r[s[i]-'a']++;
        R[t[i]-'a']++;
    }
    for(i=0;i<26;i++){
        int num=r[i];
        for(j=0;j<26;j++){
            if(R[j]==num){
                R[j]=0;
                break;
            }
        }
        if(j==26){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s",s,t);
     ^