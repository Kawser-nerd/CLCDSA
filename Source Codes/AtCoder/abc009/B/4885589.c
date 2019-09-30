#include <stdio.h>
#define max_menu_len 110
#define max_prise_len 1010
void initArray(int a[], int len);
int main(void)
{
    int n;
    scanf("%d", &n);
    int menu[max_menu_len];
    int prise[max_prise_len];
    initArray(menu, max_menu_len);
    initArray(prise, max_prise_len);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &menu[i]);
    }
    for (int i = 0; i < n; i++)
    {
        prise[menu[i]] = 1;
    }
    int num = max_prise_len - 1;
    int count = 0;
    do
    {
        if(prise[num] > 0)
        {
            count++;
        }
        num--;
    } while (count < 2);

    printf("%d\n", num + 1);
    return 0;          
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &menu[i]);
         ^