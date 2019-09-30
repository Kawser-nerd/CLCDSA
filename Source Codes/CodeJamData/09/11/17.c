#include<stdio.h>
int run(int n, int b){
    int i, sum=0;
    while(n!=0)
    {
        i=n%b;
        n/=b;
        sum+=i*i;
    }
    return sum;
}
int test(int n, int b) {
    int i, j;
    int t=0;
    int stack[4096];
    while(1)
    {
        if((n=run(n, b))==1)
            return 1;
        for(j=0;j<t;j++)
            if(stack[j]==n)
                return 0;
        stack[t++] = n;
    }
}

int main(){
    int t, i, j, n, c, pass;
    int b[9];
    char s[1024];

    scanf("%d ", &t);
    for(i=0;i<t;i++)
    {
        fgets(s, 1024, stdin);
        n = sscanf(s, "%d %d %d %d %d %d %d %d %d ", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8]);
        for(c=2,pass=0;!pass;c++)
        {
            pass=1;
            for(j=0;j<n;j++)
            {
                if(test(c, b[j])==0) pass=0;

            }
        }
        printf("Case #%d: %d\n", i+1, c-1);
    }
    return 0;
}
