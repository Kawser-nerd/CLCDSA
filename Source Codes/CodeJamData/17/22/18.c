#include<stdio.h>

char findMax();


int main()
{
    int t;
    scanf("%d",&t);
    for(int l=0;l<t;l++)
    {
        int n,r,o,y,g,b,v;
        scanf("%d %d %d %d %d %d %d",&n,&r,&o,&y,&g,&b,&v);
        char arr[n];
        if(r>n/2 || y>n/2 ||b>n/2)
            printf("Case #%d: IMPOSSIBLE\n",l+1);
        else
        {
        for(int i=0;i<n;i++)
        {int flag=0;
        char max;
        int tempr=0,tempy=0,tempb=0;
        while(flag==0)
        {
        
        max = findMax(r,y,b);

        //printf("|%c|",max);

        if(max=='Y')
        {
                y--;
                tempy++;
        }
        if(max=='B')
                {b--;
                tempb++;
                }
        if(max=='R')
                {r--;
                tempr++;
        }

        if(arr[i-1]!=max || i==0)
            {flag=1;
            y = y + tempy;
            b=  b + tempb;
            r = r + tempr;
            if(max=='Y')
                y--;
        
        if(max=='B')
                b--;
                
        if(max=='R')
                r--;
        

            }
        
        }

       
        arr[i] = max;
            
        

        }

    if(arr[n-1]==arr[0])
        {char temp = arr[n-1];
        arr[n-1] = arr[n-2];
        arr[n-2] = temp;
        }

    printf("Case #%d: ",l+1);
    for(int i=0;i<n;i++)
        printf("%c",arr[i]);
        printf("\n");
    
        }
    }
    return 0;
}

char findMax(int r, int y, int b)
{
if(r>=b && r>=y && r>0)
    return 'R';
if(y>=b && y>=r && y>0)
    return 'Y';
if(b>=r && b>=y && b>0)
    return 'B';
}