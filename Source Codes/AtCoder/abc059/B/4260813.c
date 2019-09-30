#include <stdio.h>
#include <string.h>

int main(void){
    char a[100],b[100];
    int a_len,b_len;
    int i;
    scanf("%s",a);
    scanf("%s",b);

    a_len = strlen(a);
    b_len = strlen(b);

    if (a_len > b_len)
    {
        printf("GREATER");
        return 0;
    }
    else if (a_len < b_len)
    {
        printf("LESS");
        return 0;
    }

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] > b[i])
        {
            printf("GREATER");
            return 0;
        }
        else if (a[i] < b[i])
        {
            printf("LESS");
            return 0;
        }
    }
    printf("EQUAL");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",b);
     ^