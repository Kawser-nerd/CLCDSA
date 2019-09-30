
#include <stdio.h>

char keys[101];

char target[101];

char typed[101];


int matches;
int maxmatches;
int lines;
int K,L,S;

int cmpN(char *a, char *b, int n) {
    int i;
    for (i=0;i<n;i++) {
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

void score(void) {
    int i;
    int m=0;
    typed[S]=0;
    for (i=0;i<S;i++) {
        if (cmpN(typed+i,target,L)) m++;
    }
    if (m>maxmatches) maxmatches=m;
    matches+=m;
    lines++;
}

void countBaseK(int i) {
    int j;
    if (i==S) {score();return;}
    for (j=0;j<K;j++) {
        typed[i]=keys[j];
        countBaseK(i+1);
    }
}

int canbetyped(void) {
    int i,j,found;
    for (i=0;i<L;i++) {
        found=0;
        for (j=0;j<K;j++) {
            if (target[i]==keys[j]) found=1;
        }
        if (!found) return 0;
    }
    return 1;
}

int predictmax(void) {
    int overlap,ans,i;
    if (!canbetyped()) return 0;
    overlap=0;
    for (i=1;i<L;i++) {
        if (cmpN(target,target+L-i,i)) overlap=i;
    }
    ans=1+(S-L)/(L-overlap);
    if (ans<0) ans=0;
    return ans;
}

int predictmatch(void) {
    int i,j,found;
    int per=1;
    int ans;
    if (!canbetyped()) return 0;
    for (i=0;i<L;i++) {
        found=0;
        for (j=0;j<K;j++) {
            if (target[i]==keys[j]) found++;
        }
        per*=found;
    }
    ans=1;
    for (i=0;i<S-L;i++) ans*=K;
    ans=ans*(1+S-L);
    ans=ans*per;
    return ans; 
}

double predaverage(void) {
   int i,j,found;
    double ave=1;
    if (!canbetyped()) return 0.0;
    for (i=0;i<L;i++) {
        found=0;
        for (j=0;j<K;j++) {
            if (target[i]==keys[j]) found++;
        }
        ave*=1.0*found/K;
    }
    return ave*(1.0+S-L);
 }

void docase(void) {
    int predmax;
    int predmat;
    double predave;
    scanf("%d %d %d",&K,&L,&S);
    scanf("%s",keys);
    scanf("%s",target);
    matches=maxmatches=lines=0;
    /*
    countBaseK(0);
    if (lines!=0) 
        printf("%.7f\n",maxmatches-1.0*matches/lines);
    else
        printf("0\n");
    predmax=predictmax();
    printf("   max=%d(%d) ",maxmatches,predmax);
    if (predmax!=maxmatches) printf("WRONG!");
    printf("\n");
    
    predmat=predictmatch();
    printf("  mat=%d(%d) ",matches, predmat);
    if (predmat!=matches) printf("BAD!");
    printf("\n");
    
    predave=predaverage();
    printf("  ave=%.3f(%.3f)  ",1.0*matches/lines,predave);
    if (predave-1.0*matches/lines>1e-6 || 
        1.0*matches/lines-predave>1e-6) printf("ARRGH!");
    printf("\n");    
    */
    printf("%.7f\n",predictmax()-predaverage());
}

int main(int argc, char **argv) {
    int T;
    int casenum;
    scanf("%d",&T);
    for (casenum=1;casenum<=T;casenum++) {
        printf("Case #%d: ",casenum);
        docase();
    }
    return 0;
}
