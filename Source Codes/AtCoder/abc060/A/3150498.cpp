#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int main()
{

    string a, b, c;
    while(cin >> a >> b >> c)
    {
        int lena = a.length();
        int lenb = b.length();
        if(a[lena-1] == b[0] && b[lenb-1] == c[0])
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}