#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main(){
    set<int> st;
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(st.count(x)==0)
            st.insert(x);
        else st.erase(x);
    }
    printf("%d\n",st.size());
    return 0;
} ./Main.cpp:15:19: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d\n",st.size());
            ~~    ^~~~~~~~~
            %lu
1 warning generated.