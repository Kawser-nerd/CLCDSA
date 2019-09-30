#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 50001
#include <iomanip>
#include <string>
using namespace std;


int main()
{
    int ans=0,N,temp;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        ans+=temp-1;
    }
    cout<<ans;


}