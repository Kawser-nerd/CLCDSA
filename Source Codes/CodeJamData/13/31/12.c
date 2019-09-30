
#include <stdio.h>
#include <stdlib.h>


char name[1000100];
int cons;
long long answer;

long long quartz(void) {
    int i,j,c;
    scanf("%s %d",name,&cons);
    answer=0;
    j=0;
    c=0;
    for (i=0;name[i];i++) {
        if (name[i]=='a' || name[i]=='e' ||
            name[i]=='i' || name[i]=='o' || name[i]=='u') c=0;
        else c++;
        if (c>=cons) j=i-cons+2;
        answer+=j;
    }
    return answer;
}

int main(int argc, char **argv) {
    int t,i;
    scanf("%d",&t);
    for (i=1;i<=t;i++) 
        printf("Case #%d: %lld\n",i,quartz());
    return 0;
}