#include <stdio.h>

#define DOIT(n) count[n] = (count[n] + count[n-1]) % 10000

int main()
{
    int case_count, case_index;
    int count[19], i;
    char read;
    
    scanf("%d", &case_count);
    getchar();
    for (case_index=1; case_index<=case_count; case_index++)
    {
        for (i=0; i<19; i++)
            count[i] = 0;
        while ((read = getchar()) != '\n')
        {
            switch (read)
            {
                case 'w':
                count[0]++;
                break;
                
                case 'e':
                DOIT(1);
                DOIT(6);
                DOIT(14);
                break;
                
                case 'l':
                DOIT(2);
                break;
                
                case 'c':
                DOIT(3);
                DOIT(11);
                break;
                
                case 'o':
                DOIT(4);
                DOIT(9);
                DOIT(12);
                break;
                
                case 'm':
                DOIT(5);
                DOIT(18);
                break;
                
                case ' ':
                DOIT(7);
                DOIT(10);
                DOIT(15);
                break;
                
                case 't':
                DOIT(8);
                break;
                
                case 'd':
                DOIT(13);
                break;
                
                case 'j':
                DOIT(16);
                break;
                
                case 'a':
                DOIT(17);
                break;
            }
        }
        printf("Case #%d: %04d\n", case_index, count[18]);
    }
    return 0;
}
