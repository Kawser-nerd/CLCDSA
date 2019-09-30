#include<stdio.h>

int ip[20000], a[20000], b[20000];

int main(void){
    int i, N, p;
    
    scanf("%d", &N);
    
    for(i = 0; i < N ; i++){
        scanf("%d", &p);
        ip[p - 1] = i;
    }
    
    for(i = 0; i < N; i++){
        a[i] = b[N - i - 1] = 20000 * i + 1;
    }
    
    for(i = 0; i < N; i++) a[i] += ip[i];
    
    
    printf("%ld", a[0]);
    for(i = 1; i < N; i++) printf(" %ld", a[i]);
    printf("\n%ld", b[0]);
    for(i = 1; i < N; i++) printf(" %ld", b[i]);
    printf("\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:12: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
     printf("%ld", a[0]);
            ^
./Main.c:23:35: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
     for(i = 1; i < N; i++) printf(" %ld", a[i]);
                                   ^
./Main.c:24:12: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
     printf("\n%ld", b[0]);
            ^
./Main.c:25:35: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
     for(i = 1; i < N; i++) printf(" %ld", b[i]);
                                   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]...