#include<iostream>
#include<vector>
#include<string>
using namespace std;
int fac[4]={2,3,5,7};
unsigned long long soln[2][50][300];
int init[2][50][300];
int MOD;
int size;
string str="";
unsigned long long recur(int sign,int pos,int modf)
{ if(pos==size)
  { if(modf==0&&sign==0)
    return 1;
    else
    return 0;
  }
  if(init[sign][pos][modf]!=-1)
  return soln[sign][pos][modf];
  unsigned long long&res=soln[sign][pos][modf];
  init[sign][pos][modf]=0;
  res=0;
  int modc=0;
  for(int j=pos;j<size;j++)
  { modc=(modc*10+str[j]-'0')%MOD;
    int temp=modc;
    if (sign==1)
    modc=MOD-modc;
    int req=0;
    if(modf<modc)
    req=MOD-modc+modf;
    else 
    req=modf-modc;
    res+=recur(0,j+1,req);
    res+=recur(1,j+1,req);
    modc=temp;
  }
  //if(MOD==3)
  //cout<<sign<<" "<<pos<<" "<<modf<<" "<<res<<"\n";
  return res;
}
      
    
int main()
{ int T;
  cin>>T;
  char arr[100]="";
  for(int t=0;t<T;t++)
  { cin>>arr;
    str=arr;
    //cout<<str<<"\n";
    size=str.size();
    unsigned long long sum=0;
    for(int i=1;i<16;i++)
    { int divf=1;
      int mul=-1;
      for(int j=0;j<4;j++)
      if((i>>j)&1)
      { divf*=fac[j];
        mul=-mul;
      }
      MOD=divf;
      for(int a=0;a<2;a++)
      for(int j=0;j<50;j++)
      for(int k=0;k<300;k++)
      init[a][j][k]=-1;
      unsigned long long res=recur(0,0,0);
     // if(divf==3)
      //cout<<(i&1)<<((i&2)>>1)<<((i&4)>>2)<<((i&8)>>3)<<" "<<divf<<" "<<mul<<" "<<res<<"\n";
      sum+=res*mul;
    }
    cout<<"Case #"<<t+1<<": "<<sum<<"\n";
  }
}
        
