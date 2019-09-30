#include<stdio.h>
#include<string.h>

#define ULL unsigned long long

ULL getnumber (const char* s)
{
    int i;
    ULL n = 0;
    for(i=0; s[i]!=0; i++) n = n*10 + (s[i]-'0');
    return n;
}

int main()
{
    int i, j, x, T;
    char C[18+1];
    char J[18+1];
    char a[18+1];
    char b[18+1];
    char CS[18+1];
    char JS[18+1];
    char found;
    ULL na, nb, diff;
    ULL ba, bb, best;

    scanf("%d", &T);

    for(x=1; x<=T; x++)
    {
        best = -1;
        scanf("%s %s", C, J);
        for(i=0; C[i]!=0; i++) a[i] = (C[i]=='?') ? '0' : C[i]; a[i]=0;
        for(j=0; J[j]!=0; j++) b[j] = (J[j]=='?') ? '0' : J[j]; b[j]=0;

        while(1)
        {
            na = getnumber(a);
            nb = getnumber(b);
            diff = (na>nb) ? na-nb : nb-na;
            //printf("na=%llu  nb=%llu  diff=%llu  best=%lld\n", na, nb, diff, best);
            if(best==-1 || diff < best
            || (diff==best && na<ba)
            || (diff==best && na==ba && nb<bb) )
            {
                best = diff;
                ba = na;
                bb = nb;
                strcpy(CS, a);
                strcpy(JS, b);
            }
            found=0;
            if(!found) { for(i=0; a[i]!=0; i++) if(C[i]=='?') { if(a[i]=='9') a[i]='0'; else { a[i]++; found=1; break; } } }
            if(!found) { for(i=0; b[i]!=0; i++) if(J[i]=='?') { if(b[i]=='9') b[i]='0'; else { b[i]++; found=1; break; } } }
            if(!found) break;
            //printf("------------------------ %s %s\n", a, b);
        }

        printf("Case #%d: %s %s\n", x, CS, JS);
    }
}

