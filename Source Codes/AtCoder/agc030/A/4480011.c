main()
{
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    printf("%d", A+B>=C?B+C:A+B+B+1);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:5: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
     scanf("%d%d%d", &A, &B, &C);
     ^
./Main.c:4:5: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:5: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d", A+B>=C?B+C:A+B+B+1);
     ^
./Main.c:5:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’