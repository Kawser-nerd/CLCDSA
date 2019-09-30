#include<cstdio>
#include<vector>
using namespace std;
int main(){
    vector<int> b,a;
    int n,x,f=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        b.push_back(x);
    }
    while(f){
        f=0;
        for(int i=b.size()-1;i>=0;i--){
            if(b[i]==i+1){
                f=1;
                a.push_back(b[i]);
                b.erase(b.begin()+i);
                break;
            }
        }
    }
    if(b.empty()){
        for(int i=a.size()-1;i>=0;i--){
            printf("%d\n",a[i]);
        }
    }
    else{
        printf("-1\n");
    }
}