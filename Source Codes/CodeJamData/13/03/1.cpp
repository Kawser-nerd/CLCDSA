#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100
vector<string> all;

bool cmp(const string& s1, const string& s2)
{
    if(s1.length() < s2.length())
        return true;
    if(s1.length() > s2.length())
        return false;
    return s1 < s2;
}

bool check(string val)
{
    if(val=="")
        return true;
    vector<int> sum(val.length()*2-1);
    for(int i=0; i<val.length(); i++)
        for(int j=0; j<val.length(); j++){
            int v1=val[i]-'0';
            int v2=val[j]-'0';
            sum[i+j]+=v1*v2;
        }
    for(int i=0; i<sum.size(); i++)
        if(sum[i]>=10)
            return false;
    string res(sum.size(), ' ');
    for(int i=0; i<sum.size(); i++)
        res[i]=sum[i]+'0';
    if(res.size() > MAX)
    {
        return false;
    }
    if(res[0]!='0')
        all.push_back(res);
    return true;
}

void dfs(string val)
{
    if(!check(val))
        return;
    for(int i=0; i<4; i++){
        string s = string(1, i+'0');
        dfs(s+val+s);
    }
}

int solve(string A, string B){

    int res=0;
    for(int i=0; i<all.size(); i++){
        string& S=all[i];
        if(!cmp(S, A) && !cmp(B, S))
            res++;
    }
    return res;
}

int main(){
    dfs("");
    dfs("0");
    dfs("1");
    dfs("2");
    dfs("3");
    fprintf(stderr, "found %d\n", all.size());
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        char A_[102], B_[102];
        string A, B;
        scanf("%s %s", A_, B_);
        A=A_;
        B=B_;
        printf("Case #%d: %d\n", t, solve(A, B));
    }
}
