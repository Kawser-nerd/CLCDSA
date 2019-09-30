#include <stdio.h>

int main()
{
    int i, x, T;
    char S[2000+1];
    int chr[26];
    int num[10];

    scanf("%d", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%s", S);

        for(i=0; i<10; i++) num[i]=0;
        for(i=0; i<26; i++) chr[i]=0;

        for(i=0; S[i]!=0; i++) { if(S[i]=='Z') { num[0]++; chr['O'-'A']++; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='W') { num[2]++; chr['O'-'A']++; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='U') { num[4]++; chr['O'-'A']++; chr['F'-'A']++; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='X') { num[6]++; chr['S'-'A']++; chr['I'-'A']++; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='G') { num[8]++; chr['H'-'A']++; chr['I'-'A']++; } }

        for(i=0; S[i]!=0; i++) { if(S[i]=='H') { if(chr['H'-'A']==0) { num[3]++; } else chr['H'-'A']--; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='S') { if(chr['S'-'A']==0) { num[7]++; } else chr['S'-'A']--; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='F') { if(chr['F'-'A']==0) { num[5]++; chr['I'-'A']++; } else chr['F'-'A']--; } }

        for(i=0; S[i]!=0; i++) { if(S[i]=='O') { if(chr['O'-'A']==0) { num[1]++; } else chr['O'-'A']--; } }
        for(i=0; S[i]!=0; i++) { if(S[i]=='I') { if(chr['I'-'A']==0) { num[9]++; } else chr['I'-'A']--; } }

        printf("Case #%d: ", x);
        for(i=0; i<num[0]; i++) printf("0");
        for(i=0; i<num[1]; i++) printf("1");
        for(i=0; i<num[2]; i++) printf("2");
        for(i=0; i<num[3]; i++) printf("3");
        for(i=0; i<num[4]; i++) printf("4");
        for(i=0; i<num[5]; i++) printf("5");
        for(i=0; i<num[6]; i++) printf("6");
        for(i=0; i<num[7]; i++) printf("7");
        for(i=0; i<num[8]; i++) printf("8");
        for(i=0; i<num[9]; i++) printf("9");
        printf("\n");
    }
}

