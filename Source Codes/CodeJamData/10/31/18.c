#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int case_max,case_num;
    int n, num, line[1000][2];
    int i, j;
    FILE *fpin,*fpout;
    fpin=fopen("A-large.in", "r");
    fpout=fopen("A-large.out", "w");
    fscanf(fpin, "%d\n", &case_max);
    for(case_num=0; case_num<case_max; case_num++)
    {
        num=0;
        fscanf(fpin,"%d\n", &n);
        for(i=0; i<n; i++)
            fscanf(fpin,"%d %d\n", &line[i][0], &line[i][1]);
        for(i=0; i<n; i++)
        {
            for(j=0;j<i;j++)
            {
                if((line[i][0]>line[j][0]&&line[i][1]<line[j][1])||(line[i][0]<line[j][0]&&line[i][1]>line[j][1]))
                    num++;
            }
        }
        fprintf(fpout, "Case #%d: %d\n", case_num+1, num);
    }
    return 0;
}
