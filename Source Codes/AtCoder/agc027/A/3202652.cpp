#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long int arr[2000];
int main(){
    long long int n,num,sum=0;
    memset(arr,0,sizeof(arr));
    cin>>n>>num;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int i;
    for(i=0;i<n;i++){
        if(num>=arr[i]){
            sum+=1;
            num-=arr[i];
        }else break;
    }
    if(i==n&&num>0)sum--;
    cout<<sum<<endl;
return 0;
}