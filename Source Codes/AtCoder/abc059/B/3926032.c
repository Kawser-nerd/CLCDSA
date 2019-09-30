#include <stdio.h>
#include <string.h>
int comparison(char *a, char *b){
    int a_len = strlen(a);
    int b_len = strlen(b);
    if(a_len < b_len) return -1;
    else if(a_len > b_len) return 1;
    else{
        while(*a != *b){
            if(*a < *b) return -1;
            else if(*a > *b) return 1;
            else{
                a++;
                b++;
            }
        }
        return 0;
    }
}

void printResult(int i){
    switch(i){
        case 1:
        printf("GREATER\n");
        return;
        case 0:
        printf("EQUAL\n");
        return;
        case -1:
        printf("LESS\n");
        return;
    }
}

int main()
{
    int comp;
    char a[102], b[102];
    scanf("%s%s", a, b);
    comp = comparison(a, b);
    printResult(comp);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s", a, b);
     ^