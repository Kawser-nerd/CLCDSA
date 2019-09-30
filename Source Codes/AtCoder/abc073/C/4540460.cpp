#include<stdio.h>
#include <set>
#include <stdio.h>
using namespace std;
int main()
{
    int n,key;
    scanf("%d",&n);

    set<int> st;
    while(n--)
    {
        scanf("%d",&key);
        if(st.count(key)==0)
        {
            st.insert(key);
        } else
            {
                st.erase(key);
            }
    }
    printf("%d",st.size());
} ./Main.cpp:22:17: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d",st.size());
            ~~  ^~~~~~~~~
            %lu
1 warning generated.