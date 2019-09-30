#include <stdio.h>

#define MAX_L 15
#define MAX_D 5000
#define MAX_N 500

int main()
{
    int l, d, n;
    char dict[MAX_D][MAX_L+1];
    char word[28*MAX_L+1];
    int i, j, index_dict, index_word, result;
    
    scanf("%d %d %d", &l, &d, &n);
    for (i=0; i<d; i++)
        scanf("%s", dict[i]);
    
    for (j=0; j<n; j++)
    {
        scanf("%s", word);
        result = 0;
        for (i=0; i<d; i++)
        {
            index_word = 0;
            for (index_dict=0; index_dict<l; index_dict++)
            {
                if (word[index_word] == '(')
                {
                    while (word[++index_word] != ')')
                        if (word[index_word] == dict[i][index_dict])
                            break;
                    if (word[index_word] == ')')
                        break;
                    while (word[++index_word] != ')');
                }
                else if (word[index_word] != dict[i][index_dict])
                {
                    break;
                }
                index_word++;
            }
            if (index_dict==l)
                result++;
        }
        printf("Case #%d: %d\n", j+1, result);
    }
    return 0;
}
