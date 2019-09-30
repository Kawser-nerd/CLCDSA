#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
signed main(){
        int n;
        scanf("%d",&n);
        char str[256];
        scanf("%s",str);
        int a[4] = {};
        for(int i=0;i<n;i++){
                a[str[i]-'1']++;
        }
        cout << *max_element(a,a+4) << " " << *min_element(a,a+4)<< endl;
        return 0;
}