#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string n;
    int i,j,k=0,sum=0;
    cin>>n;
    for(i=0;;i++)
    {
        if(n[i]=='\0')
        {
            j=i;
            break;
        }
        if(n[i]=='9')
            k++;
    }
    if(k==j)
    {
        for(i=0;i<j;i++)
        {
            sum += (n[i]-48);
        }
    }
    else if(k==j-1&&n[0]!='9')
    {
            for(i=0;i<j;i++)
        {
            sum += (n[i]-48);
        }
    }
    else if(j==1)
    {
        sum=n[0]-48;
    }
    else
    {
        sum += (n[0]-49);
        for(i=0;i<j-1;i++)
        {
            sum += 9;
        }
    }
    printf("%d",sum);
    return 0;
}