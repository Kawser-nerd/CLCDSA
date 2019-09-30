#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
long long arr[500000];
long long inp[500000];
long long sarr[500000];
long long soln[500000];
vector<long long>fenv;
vector<long long> create(int n) { return vector<long long>(n, 0); }
map<long long,int,less<long long> >mp;
// Returns sum of elements with indexes a..b, inclusive
long long query(const vector<long long> &tree, int a, int b) {
    if(b<0)
    return 0;
    if (a == 0) {
        long long sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
          sum = (sum + tree[b])%1000000007;
        return sum; 
    } else {
        return (query(tree, 0, b) - query(tree, 0, a-1)+1000000007)%1000000007;
    }
}

// Increases value of k-th element by inc.
void increase(vector<long long> &tree, int k, long long inc) {
    for (; k < (int)tree.size(); k |= k + 1) tree[k] += inc;
}

int main()
{ int T;
  cin>>T;
  for(int t=0;t<T;t++)
  { long long n,m,X,Y,Z;
    //cout<<"\n\n";
    cin>>n>>m>>X>>Y>>Z;
    mp.clear();
    for(int i=0;i<m;i++)
    cin>>arr[i];
    int sarrl=0;
    for(int i=0;i<n;i++)
    { inp[i]=arr[i%m];
      if(!mp.count(inp[i]))
      { mp[inp[i]]=1;
        sarr[sarrl]=inp[i];
        sarrl++;
      }
      //cout<<inp[i]<<" ";
      arr[i % m] = (X * arr[i % m] + Y * (i + 1)) % Z;
    }
    sort(sarr,sarr+sarrl);
    for(int i=0;i<sarrl;i++)
    mp[sarr[i]]=i;
    long long sum=0;
    fenv=create(n);
    for(int i=0;i<n;i++)
    { soln[i]=1;
      soln[i]=(soln[i]+query(fenv,0,mp[inp[i]]-1))%1000000007;
      //if(t==1)
      //cout<<soln[i]<<" ";
      increase(fenv,mp[inp[i]],soln[i]);
      sum=(sum+soln[i])%1000000007;
    }
    cout<<"Case #"<<t+1<<": "<<sum<<"\n";
  }
}
