#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int l,t,n,k,x,i;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d",&n,&k);
        x=(1<<n);
        k%=x;
        printf("Case #%d: ",l+1);
        if ((k+1)==x)
            printf("ON\n");
        else
            printf("OFF\n");
    }
	return 0;
}

