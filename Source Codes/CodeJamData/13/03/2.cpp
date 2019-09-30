#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#define ll long long

using namespace std;

class cmp
{
    public:
        bool operator()(string a, string b)
        {
            if(a.size()==b.size())return a<b;
            else return a.size()<b.size();
        }
};

set<string, cmp> st;

bool ispal(ll v)
{
    stringstream ss;
    ss<<v;
    string s;
    ss>>s;
    string t = s;
    reverse(t.begin(), t.end());
    return s==t;
}

string strsq(string s)
{
    string vec;
    vec.resize(2*s.length()-1);
    for(int i=0; i<(int)vec.size(); i++)
    {
        vec[i] = '0';
    }
    for(int i=0; i<(int)s.length(); i++)
    {
        for(int j=0; j<(int)s.length(); j++)
        {
            vec[i+j] += (s[i]-'0') * (s[j]-'0'); 
        }
    }
    for(int i=0; i<(int)vec.size(); i++)
    {
        if(vec[i]>'9' || vec[i]<'0')return "";
    }
    return vec;
}

void dfs(string s, int mx)
{
    if((int)s.length()>mx)return;
    string r = s;
    reverse(r.begin(), r.end());
    string o = r;
    o += s;
    r += s.substr(1);
    string t = r;
    reverse(t.begin(), t.end());

    if(s[s.length()-1]!='0')
    {
        string sq = strsq(r);
        if(sq!="")st.insert(sq);

        string sq2 = strsq(o);
        if(sq2!="")st.insert(sq2);

        if(sq=="" && sq2=="")return;
    }

    if(s.size()>1 && *(--s.end())=='2')return;
    dfs(s+"0", mx);
    dfs(s+"1", mx);
    dfs(s+"2", mx);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //ll x;while(cin>>x)cout<<ispal(x)<<endl;
    //

    //freopen("Cs.in", "r", stdin);
    //freopen("Cs.out", "w", stdout);
    
    int len = 26;
    st.insert("9");
    dfs("0", len);
    dfs("1", len);
    dfs("2", len);

    vector<string> vs;

    for(set<string, cmp>::iterator it=st.begin(); it!=st.end(); it++)
    {
        //cout<<(*it)<<endl;
        vs.push_back(*it);
    }

    int cnt = 0;
    for(ll i=100000000; i<=0; i++)
    {
        if(!ispal(i))continue;
        ll sq = i*i;
        if(!ispal(sq))continue;
        cout<<i<<" / "<<sq<<endl;
        cnt++;
    }

    int N;
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        string a, b;
        cin>>a>>b;
        cout<<"Case #"<<i<<": "<<(upper_bound(vs.begin(), vs.end(), b, cmp()) - lower_bound(vs.begin(), vs.end(), a, cmp()))<<endl;
    }

    //cout<<cnt<<" / "<<st.size()<<endl;


    return 0;
}
