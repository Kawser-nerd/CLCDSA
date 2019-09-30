#include<iostream>
#include<vector>
#include<string>
using namespace std;
long long freq[1000];
int main()
{ int T;
  cin>>T;
  for(int t=0;t<T;t++)
  { int P,K,L;
    long long sum=0;
    cin>>P>>K>>L;
    for(int i=0;i<L;i++)
    cin>>freq[i];
    sort(freq,freq+L);
    long long cp=1;
    int cur=0;
    for(int i=L-1;i>=0;i--)
    { if(cur>=K)
      { cur=0;
        cp++;
      }
      sum+=freq[i]*cp;
      cur++;
    }
    cout<<"Case #"<<t+1<<": "<<sum<<"\n";
  }
}  
