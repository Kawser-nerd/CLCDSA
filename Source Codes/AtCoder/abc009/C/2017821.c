#include <stdio.h>
#include <stdlib.h>
int N,K;
char S[101];
int C[26]={0};
int D[26]={0};
int r=0;
void sol(int a,int b){
    int i,j,k;
    for(i=0;i<26;i++){
        if(C[i]>0){
            C[i]--;
            D[S[a]-'a']--;
            int t=b;
            if(i!=S[a]-'a')t++;
            int dif=0;
            for(j=0;j<26;j++){
                if(D[j]>C[j])dif+=D[j]-C[j];
            }
            if(dif+t>K){
                C[i]++;
                D[S[a]-'a']++;
                continue;
            }else{
                r++;
                printf("%c",'a'+i);
                if(r==N)printf("\n");
            }
            if(t<K){
                sol(a+1,t);
            }
            break;
        }
    }
}
int main(){
    scanf("%d %d",&N,&K);
    scanf("%s",S);
    int i,j;
    for(i=0;i<N;i++){
        C[S[i]-'a']++;
        D[S[i]-'a']++;
    }
    sol(0,0);
    //printf("%d\n",r);
    for(i=r;i<N;i++){
        if(C[S[i]-'a']>0){
            if(D[S[i]-'a']>C[S[i]-'a']){
                printf("%c",S[i]);
                C[S[i]-'a']--;
                D[S[i]-'a']--;
            }else{
                int flag=1;
                for(j=0;j<S[i]-'a';j++){
                    if(C[j]>D[j]){
                         printf("%c",j+'a');
                    C[j]--;
                    D[j]--;
                    flag=0;
                    break;
                    }
                }
                if(flag)printf("%c",S[i]);
            }
        }else{
            for(j=0;j<26;j++){
                if(C[j]>D[j]){
                    printf("%c",j+'a');
                    C[j]--;
                    D[j]--;
                }
            }
        }
        if(i==N-1)printf("\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&K);
     ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^