#include <stdio.h>
#include <math.h>

#define MxA 100
#define mod (2*3*5*7)

int tmp, gi(), ga(int*,int), proc();
int NC, nc;
long long ans;
int N,M;
int i, j, k, l, m;
char s[MxA];
char s2[2*MxA];
int slen;
long long sum;

int main(int c, char* v[]) {
    NC = gi();
    fgetc(stdin);
    for (nc=0; nc<NC; nc++) {
        fgets(s, MxA, stdin);
        s[strlen(s)-1]=0;
        slen = strlen(s);

        proc();

        printf("Case #%d: ", nc+1);
        printf("%Ld\n", ans);
    }
}
int ugly(long long int N) {
    if (N%2==0) return 1;
    if (N%3==0) return 1;
    if (N%5==0) return 1;
    if (N%7==0) return 1;
    return 0;
}

int evaluate(char* s) {
    long long term, sum;
    int l = strlen(s );
    char prev;
    sum = 0L;
    term = 0L;
    prev = '+';
    for (i=0; i<l; i++) {
        if (s[i]=='+'||s[i]=='-') {
            if (prev=='+') sum += term;
            else sum -= term;
            sum = sum % mod;
            term = 0L;
            prev = s[i];
            continue;
        }
        term = term*10 + (s[i]-'0');
        term = term % mod;
    }
    if (prev=='+') sum += term;
    else sum -= term;
    if (ugly(sum)) ans++;

// printf("%s->%Ld\n", s, sum);
}

int zzz(int pos, int pos2) {
    if (pos == slen) {
        s2[pos2]=0;
        evaluate(s2);
    } else {
        s2[pos2] = s[pos];
        zzz(pos+1, pos2+1);
        if (pos>0) {
            s2[pos2] = '+';
            s2[pos2+1] = s[pos];
            zzz(pos+1, pos2+2);
            s2[pos2] = '-';
            zzz(pos+1, pos2+2);
        }
    }
}

int proc() {
    ans=0LL;
    for (i=0; i<MxA; i++) s2[i]=0;
    zzz(0, 0);
}


int gi() {fscanf(stdin,"%d",&tmp);return tmp;}
int ga(int*ary,int n){int i; for (i=0;i<n;i++)fscanf(stdin,"%d",&(ary[i]));}
