#include <stdio.h>
int main(void){
    
    char s[1001];
    int cntn=0, cnts=0, cnte=0, cntw=0, i=0;

    scanf("%s", s);

    while(s[i] != '\0'){
        if(s[i]=='N') cntn++;
        else if(s[i]=='S') cnts++;
        else if(s[i]=='E') cnte++;
        else if(s[i]=='W') cntw++;
        i++;
    }

    if(((cntn==0 && cnts==0) || (cntn>0 && cnts>0)) &&
       ((cnte==0 && cntw==0) || (cnte>0 && cntw>0))) printf("Yes\n");
    else printf("No\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^