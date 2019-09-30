#include <iostream>

using namespace std;
int cnt[10];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int p=0;
    for(int i=0;i<n;i++){
        if(a[i]<3200){
            if(a[i]<400)cnt[1]=1;
            else if(a[i]<800)cnt[2]=1;
            else if(a[i]<1200)cnt[3]=1;
            else if(a[i]<1600)cnt[4]=1;
            else if(a[i]<2000)cnt[5]=1;
            else if(a[i]<2400)cnt[6]=1;
            else if(a[i]<2800)cnt[7]=1;
            else if(a[i]<3200)cnt[8]=1;



        }
        else p++;

    }
    int s=0;
    for(int i=1;i<9;i++)s+=cnt[i];
    if(s==0)cout<<1<<" "<<p;
    else
    cout<<s<<" "<<s+p;
    return 0;
}