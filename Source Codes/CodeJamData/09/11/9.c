// std=c99

#include <stdio.h>

int main()
{
   int T;
    char line[1024];
    int base[16];
    unsigned long long stk[100], stkp=0;

    scanf("%d\n", &T);

    for (int casei=0;casei<T;casei++)
    {
        fgets(line, 1024, stdin);

        for (int i=0;i<16;i++)
            base[i] = 0;

        for (int i=0;line[i];i++)
        {
            if (line[i] == ' ') continue;
            if (line[i] == '1')
            {
                base[10] = 1; i++; continue;
            }
            base[line[i]-'0'] = 1;
        }

        for (unsigned long long n=2;;n++)
        {
        int good = 1;
        for (int basei=10;basei>=2;basei--)
        {
            if (!base[basei]) continue;

            //printf("here %d %d\n", basei, n);
            unsigned long long copy = n;
            unsigned long long new = 0, copy2 = -1;
            //happify
            stkp=0;
            while (new!=copy2)
            {
                    if (!copy) copy = new;
                    copy2 = copy;
                    new = 0;
                    while (copy)
                    {
                        int temp= (copy%basei);
                        new += temp*temp;
                        copy /= basei;
                    }
                    if (new == 1) break;
              //      printf("in %d\n", new);
                    for (int j=0;j<stkp;j++)
                    {
                        if (new==stk[j])
                        {
                            good = 0; break;
                        }
                    }
                    if (!good) break;
                    stk[stkp++] = new;
            }
            if (!good) break;

//            printf("%d\n", new);

            if (new != 1)
            {
                good = 0;
                break;
            }
        }
        if (good)
        {
            printf("Case #%d: %llu \n", (casei+1), n);
            break;
        }
        }
    }
}
