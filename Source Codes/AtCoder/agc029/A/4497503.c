main()
{
    char S[200001];
    scanf("%s", S);
    long long i, l=strlen(S), w=0, ans=0;
    for(i=0;i<l;i++)
    {
        if(S[i]=='W') ans+=(i-w++);
    }
    printf("%lld",ans);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:5: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
     scanf("%s", S);
     ^
./Main.c:4:5: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:5: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:20: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
     long long i, l=strlen(S), w=0, ans=0;
                    ^
./Main.c:5:20: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:20: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:10:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%lld",ans);
     ^
./Main.c:10:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:10:5: note: include ‘<stdio.h>’ or provide a declaration of ...