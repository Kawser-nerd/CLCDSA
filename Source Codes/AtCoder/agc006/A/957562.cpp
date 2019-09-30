#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str1[105],str2[105];
    int n,x,y,t,flag;
    char* t1=str1;
    char* t2=str2;
    while(~scanf("%d",&n))
    {
        t=0;
        scanf("%s%s",str1,str2);
        y=0,flag=0;
        for(x=0;x<n;x++)
        {
            flag=1,y=0;
            while(flag&&y<n-x)
            {
                flag=0;
                if(str1[x+y]==str2[y])
                {
                    flag=1;
                    y++;
                }
            }
            if(x+y==n)
                break;
        }
        printf("%d\n",2*n-y);

    }
    return 0;
}