#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
int main()
{
    int n; scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        if(s.find(a) == s.end()){
            s.insert(a);
            cnt++;
        }else{
            s.erase(a);
            cnt--;
        }
    }
    printf("%d\n", cnt);
    return 0;
}