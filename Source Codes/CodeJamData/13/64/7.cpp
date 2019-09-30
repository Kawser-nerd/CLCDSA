//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;


int testId;
int k;
             
struct three{
    int a[3];
    void norm(){
        sort(a, a+3);
    }
    three(){
        a[1] = a[2] = -2;
        a[0] = -2 + (k == 2);
    }
    bool operator==(const three& r) const{
        for (int i = 0; i < 3; i++)
            if (r.a[i] != a[i]) 
                return false;
        return true;
    }

    bool operator<(const three& r) const{
        for (int i = 0; i < 3; i++)
            if (r.a[i] != a[i]) 
                return a[i] < r.a[i];
        return false;
    }
};

bool join(const three& t1, const three& t2, three& res){
    vector<int> tmp(6);    
    merge(t1.a,t1.a+3,t2.a,t2.a+3,tmp.begin());           
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    if (tmp[0] == -2) tmp.erase(tmp.begin());
/*    for (int i = 0; i < (int)tmp.size(); i++)
        eprintf("    %d",tmp[i]);
    eprintf("\n");*/
    if (tmp.size() > 3) return false;
    while (tmp.size() < 3) tmp.pb(-2);
    for (int i = 0; i < 3; i++)
        res.a[i] = tmp[i];
    res.norm();
    return true;
}

vector<three> intersec(const vector<three>& a,const vector<three>& b){
    vector<three> res;
    for (int i = 0; i < (int)a.size(); i++){        
        bool found = 0;
        for (int j = 0; j < (int)b.size(); j++){
            three tmp;
            if (join(a[i], b[j], tmp)){
                if (tmp == a[i]){
                    res.pb(tmp);
                    found = true;
                    break;
                }
            }
        }              
        
        if (found) continue;

        for (int j = 0; j < (int)b.size(); j++){
            three tmp;
            if (join(a[i], b[j], tmp)){
                res.pb(tmp);
            }
        }    
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
//    assert(res.size() <= 64);
    return res;
}
       


vector<three> tree[270000];
int lst;


bool check(int l,int r){
    l += lst;
    r += lst;
    vector<three> res;
    res.pb(three());
    while (l < r){
  //      eprintf("%d %d %d\n",l,r,res.size());
        if ((l & 1) == 1)
            res = intersec(res, tree[l]), l++;
        if ((r & 1) == 1)
            res = intersec(res, tree[r-1]), r--;
        l = l / 2;
        r = r / 2;
    }                          
    return res.size() != 0;
}
                                   

void PreCalc(){
}

void solve(){
    int n,d,k;
    scanf("%d %d %d",&n,&d,&k);
    
    lst = 2;
    while (lst < n) lst *= 2;

    for (int i = 1; i < 2*lst; i++) tree[i].clear();

                    

    for (int i = 0; i < n; i++){
        tree[i+lst].resize(d);
        for (int j = 0; j < d; j++){
            scanf("%d\n", &tree[i+lst][j].a[0]);
            tree[i+lst][j].a[1] = -2;
            tree[i+lst][j].a[2] = -2 + (k == 2);
            tree[i+lst][j].norm();
        }
        sort(tree[i+lst].begin(),tree[i+lst].end());
    }            

//    if (testId != 11) return;
    for (int i = lst - 1; i > 0; i--)
        tree[i] = intersec(tree[2*i], tree[2*i+1]);


                                                  

    int ans = 0;
    int bl,br;
    bl = br = -1;

    int rg = 0;
            
    for (int lf = 0; lf < n; lf++){
       
        for (; rg <= n; rg++){                           
            if (!check(lf, rg)) {            
                rg--;
                break;
            }
            if (ans < rg - lf){
                ans = rg - lf;
                bl = lf;
                br = rg-1;
            }
        }
        if (lf % 1000 == 0)
        eprintf("%d %d %d\n",lf,rg,ans);

    }
    printf("%d %d\n", bl, br);
}



int main(){
  freopen(TASKNAME"-"TASKMOD".in","r",stdin);
  freopen(TASKNAME"-"TASKMOD".out","w",stdout);
    
  PreCalc();
  TIMESTAMP(PreCalc);   
                                               
  char buf[1000];
  int testNum;
  gets(buf);
  sscanf(buf,"%d",&testNum);

  for (testId = 1; testId <= testNum; testId++){
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0){
        TIMESTAMPf("Test %d",testId);
    }
    printf("Case #%d: ",testId);
    solve();                        
  }
      
  TIMESTAMP(end);
  return 0;
}