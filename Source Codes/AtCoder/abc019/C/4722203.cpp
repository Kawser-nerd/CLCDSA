#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,a;
    vector<int> v;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        while(a%2==0){
            a/=2;
        }
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    printf("%ld\n",v.size());
}