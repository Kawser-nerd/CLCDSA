#include<iostream>
using namespace std;
int main()
{
    int h,w,d;
    cin>>h>>w>>d;
    int x[90001];
    int y[90001];
    int a;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a;
            x[a]=j,y[a]=i;
        }
    }
    int sum[90001];
    for(int i=1;i<=d;i++){
        sum[i]=0;
    }
    for(int i=d+1;i<=h*w;i++){
        sum[i]=sum[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d]);
    }
    int q;
    cin>>q;
    int L[q],R[q];
    for(int i=0;i<q;i++)
    {
        cin>>L[i]>>R[i];
        cout<<sum[R[i]]-sum[L[i]]<<endl;
    }
    return 0;
}