
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000000007LL

//char *train[10];
int N;
int count;

int embedded[26];
int oneletter[26];
int endswith[26];
int startswith[26];
int impossible=0;

int used;
int segment;

char *destutter(char *s) {
    static char buf2[200];
    char *d=buf2;
    char last=0;
    while (*s) {
        if (*s!=last) last=*d++ = *s;
        s++;
    }
    *d=0;
    return buf2;
}

void readtrains(void) {
    int i,len,j;
    static char buff[200];
    char *b;
    impossible=0;
    scanf("%d",&N);
    for (i=0;i<26;i++) {
        embedded[i]=0;
        oneletter[i]=0;
        endswith[i]=-1;
        startswith[i]=-1;        
    }
    for (i=0;i<N;i++) {
        scanf("%s",buff);
        b=destutter(buff);
        len=strlen(b);
        if (len==1) {
            oneletter[*b-'a']++;
            continue;
        }
        if (startswith[*b-'a']>=0) impossible++;
        if (endswith[b[len-1]-'a']>=0) impossible++;
        startswith[*b-'a']=b[len-1]-'a';
        endswith[b[len-1]-'a']=*b-'a';
        for (j=1;j<len-1;j++) embedded[b[j]-'a']++;
    }
}

int modtimes(int a, int b) {
    return (int)((1LL*a*b) % M);
}

int factorial(int n) {
    int f=1;
    int i;
    if (n<=1) return 1;
    for (i=2;i<=n;i++) f=modtimes(f,i);
    return f;
}

void countonlyi(int i) {
    segment++;
    //printf("countonly %c seg=%d\n",'a'+i,segment);
    count=modtimes(count,segment); //for segment!
    used |= 1<<i;
    count=modtimes(count,factorial(oneletter[i]));
}

void countendi(int i) {
    segment++;
    //printf("countend %c seg=%d\n",'a'+i,segment);
    count=modtimes(count,segment); //for segment!
    while (1) {
        if ((1<<i) & used) {impossible++;return;}
        used |= 1<<i;
        count=modtimes(count,factorial(oneletter[i]));
        i=endswith[i];
        if (i<0) break;
    }
    
}

void countstarti(int i) {
    int used2=1<<i;
    //printf(" Cs %c\n",i+'a');
    while (startswith[i]>=0) {
        i=startswith[i];
        //printf(" cs %c\n",i+'a');
        if (used2 & (1<<i)) {
            //printf("imp\n");
            impossible++;return;
        }
        used2|=1<<i;
    }
    countendi(i);
}




void counttrains(void) {
    int i;
    count=1;
    used=0;
    segment=0;
    for (i=0;i<26;i++) {
        if (impossible || embedded[i]>1 || embedded[i] && (startswith[i]>=0 || endswith[i]>=0)) {
            printf("0\n"); //impossible
            return;
        }
    }
    i=0;
    while (i<26 && !impossible) {
        if (startswith[i]>=0 && !((1<<i) & used)) countstarti(i);
        if (endswith[i]>=0 && !((1<<i) & used)) countendi(i);
        if (oneletter[i]>0 && !((1<<i) & used)) countonlyi(i);
        i++;
    }
    if (impossible) printf("0\n");
    else printf("%d\n",count);
}

void dump(void) {
    int i;
    printf("\n");
    for (i=0;i<26;i++) {
        if (startswith[i]<0 && endswith[i]<0 && embedded[i]==0 && oneletter[i]==0) continue;
        printf("  %c : ->%c  %c<- em=%d 1L=%d\n",i+'a',startswith[i]+'a',endswith[i]+'a',embedded[i],oneletter[i]);
    }
}

int main(int argc, char **argv) {
    int tc,i;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        readtrains();
        //dump();
        counttrains();
    }
    return 0;
}
