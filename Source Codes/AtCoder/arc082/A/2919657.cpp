#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int a[100001],b[100001];
bool comp(int a,int b)
{
 return a>b;
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]+1]++;
        b[a[i]-1]++;
        b[a[i]]++;
    }
    sort(b,b+100001,comp);
    cout<<b[0]<<endl;

}