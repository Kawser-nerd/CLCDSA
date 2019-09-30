#include <string.h>
#include <stdio.h>
char s[100005];
//??[l,r]??0??????
int judge(int l,int r){
    //printf("%d %d\n",l,r);
    int i,z=0;
    for(i=l;i<=r;i+=2){
        if(s[i]=='0'){
            z=1;
            break;
        }
    }
    //printf("z=%d\n",z);
    return z;
}
int main(void){
    scanf("%s",s);
    int len=strlen(s);
    s[len]='+';
    s[len+1]='\0';
    //printf("%s\n",s);
    int i,l=0,ans=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='+'){
            if(judge(l,i-1)==0)ans++;
            l=i+1;
            i=l;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^