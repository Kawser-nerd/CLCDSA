#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int l=0;l<t;l++)
    {
        int d, n;
        scanf("%d %d",&d,&n);
        int *k;
        int *s;
        k = (int*) malloc(sizeof(int)*n);
        s = (int *) malloc(sizeof(int)*n);
        float max = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&k[i],&s[i]);

        }

        for(int i=n-1;i>=0;i--)
        {
            float dist = d - k[i];
            float tim = dist/s[i];

            //printf("[%f  %f]",dist,tim);

            if(tim>max)
                max = tim;
            
        //printf("|%d  %d|",k[i],s[i]);
        }

        printf("Case #%d: %f\n",l+1,d/max);

        free(k);
        free(s);
    }


    return 0;
}