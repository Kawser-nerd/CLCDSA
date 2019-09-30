#include <stdio.h>

int main()
{
    int case_index, case_count;
    char row[41];
    int size, result;
    int array[40];
    int i, j, k;
    
    scanf("%d", &case_count);
    for (case_index=1; case_index<=case_count; case_index++)
    {
        scanf("%d", &size);
        getchar();
        for (i=0; i<size; i++)
        {
            scanf("%s", row);
            array[i] = 0;
            for (j=1; j<size; j++)
                if (row[j] == '1')
                    array[i] = j;
        }
        
        result = 0;
        for (i=0; i<size; i++)
        {
            for (j=i; array[j]>i; j++);
            result += j-i;
            for (k=j; k>i; k--)
                array[k] = array[k-1];
        }
        
        printf("Case #%d: %d\n", case_index, result);
    }
    return 0;
}
