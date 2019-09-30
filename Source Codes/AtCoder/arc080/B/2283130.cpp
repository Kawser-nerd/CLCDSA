#include <iostream>
#include <string>
using namespace std;
int h,w,n,j=-1,color=1;
int main(void){
    cin>>h>>w>>n;
    int a[n+1],ans[h][w];
    for(int i=0;++i-1-n;)cin>>a[i];
    for(int i=-1;++i-h;){
        for(;(j+=(i%2)*-2+1)>-1&&j<w;){
            ans[i][j]=color;
            if(!--a[color])++color;
        }
    }
    for(int i=-1;++i-h;){
        cout<<ans[i][0];
        for(j=0;++j-w;)cout<<' '<<ans[i][j];
        cout<<endl;
    }
    return 0;
}