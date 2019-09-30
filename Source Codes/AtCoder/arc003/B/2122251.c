#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int WORD_NUM = 100;
const int STR_LEN = 20;

int main(void)
{
    // ??????????
    char str[WORD_NUM + 1][STR_LEN + 1];
    char str_tmp[STR_LEN + 1];
    int N, num, str_len, ret;

    for(int i = 0; i < WORD_NUM + 1; i++)
    {
        for(int j = 0; j < STR_LEN + 1; j++)
        {
            str[i][j] = '\0';
        }
    }

    scanf("%d", &N);

    str_len = 0;

    for(int word_num = 0; word_num < N; word_num++)
    {
        scanf("%s", str_tmp);
        num = strlen(str_tmp);

        for(int j = num - 1; j >= 0; j--)
        {
            str[word_num][str_len] = str_tmp[j];
            str_len++;
        }

        str_len = 0;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            ret = strcmp(&str[i][0], &str[j][0]);

            if( ret > 0 )
            {
                strcpy(str_tmp, &str[i][0]);
                strcpy(&str[i][0], &str[j][0]);
                strcpy(&str[j][0], str_tmp);
            }
        }
    }

    // ???????
    for(int word_num = 0; word_num < N; word_num++)
    {
        str_len = 0;

        for(int i = 0; i < STR_LEN; i++)
        {
        	str_tmp[i] = '\0';
        }

        num = strlen(&str[word_num][0]);

        for(int i = num - 1; i >= 0; i--)
        {
            str_tmp[str_len] = str[word_num][i];
            str_len++;
        }

        printf("%s\n", &str_tmp[0]);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", str_tmp);
         ^