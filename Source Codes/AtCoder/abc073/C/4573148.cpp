#include <stdio.h>
#include <set>
using namespace std;
int main()
{
    int n,x;
    scanf("%d",&n);
    set<int> st;
    for(int i=0;i<n;i++)
    {
       scanf("%d",&x);
       if(st.count(x)==0)
            st.insert(x);
       else
        st.erase(x);
    }
    printf("%d\n",st.size());
} ./Main.cpp:17:19: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d\n",st.size());
            ~~    ^~~~~~~~~
            %lu
1 warning generated.