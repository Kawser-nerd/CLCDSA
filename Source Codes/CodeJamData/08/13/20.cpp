#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int N;
int testCase,testNum;
int ansT[101];

vector<pair<int,int> > vec;

int main()
{
  cout<<setfill('0');
  cin>>testNum;
  for (testCase=1;testCase<=testNum;++testCase)
  {
    cin>>N;
    vec.push_back(make_pair(N,testCase));
  }
  sort(vec.begin(),vec.end());
  int F1=2,F2=6;
  int now=3;
  int ans=28;
  for (testCase=1;testCase<=testNum;++testCase)
  {
    N=vec[testCase-1].first+1;
    while (now<N)
    {
      F1=F2;
      F2=ans;
      //ans=6*F2-4*F1;
      ans=((6*F2-4*F1)%1000+1000)%1000;
      ++now;
    }
    //cout<<N<<' '<<ans<<endl;
    ansT[vec[testCase-1].second]=(ans-1+1000)%1000;
  }
  for (testCase=1;testCase<=testNum;++testCase)
    cout<<"Case #"<<testCase<<": "<<setw(3)<<ansT[testCase]<<endl;
}
