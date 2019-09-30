#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int a, int b){return a<b?a:b;}
int charassort(const void *a, const void *b){return strcmp((char*)a ,(char*)b);}

int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    char s[n+1],t[n+1],ans[n+1];
    scanf("%s",s);
    strcpy(t,s);
    for (int i=0; i<n; i++){
        qsort ((void*)t,n,sizeof(t[0]),charassort);
        for (int j=0; j<n; j++){
            int change=0;
            
            for (int l=0; l<i; l++){
                if (s[l]==ans[l]){
                    change++;
                }
            }
            if (t[j]==s[i]){
                change++;
            }
            int count1[50]={},count2[50]={};
                for (int l=i+1; l<n; l++){
                    count1[s[l]-'a']++;
                }
                for (int l=0; l<n; l++){
                    count2[t[l]-'a']++;
                }
                count2[t[j]-'a']--;
            
            
            for (int l=0; l<26; l++){
                change+=min(count1[l],count2[l]);
            }
            if (n-change<=k){
                ans[i]=t[j];
                t[j]='~';
                break;
            }
        }
    }
    ans[n]='\0';
    printf("%s\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^