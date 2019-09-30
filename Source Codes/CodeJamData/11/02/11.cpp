#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void tst()
{
    vector<char> seq;
    int c;
    int d;
    cin >> c;
    vector<string> comb(c);
    for(int i=0;i<c;i++)
        cin >> comb[i];
    cin >> d;
    vector<string> opp(d);
    for(int i=0;i<d;i++)
        cin >> opp[i];

    int l;
    cin >> l;
    string inp;
    cin >> inp;
    for(int i=0;i<l;i++)
    {
        seq.push_back(inp[i]);
        if(seq.size()>=2)
        {
            char a = seq[seq.size()-1];
            char b = seq[seq.size()-2];
            for(int j=0;j<c;j++)
                if((comb[j][0]==a && comb[j][1]==b)||(comb[j][0]==b && comb[j][1]==a))
                {
                    seq.pop_back();
                    seq.back() = comb[j][2];
                    break;
                }
        }
        for(int i=0;i<seq.size();i++)
            for(int j=0;j<i;j++)
            {
                char a = seq[i];
                char b = seq[j];
                for(int j=0;j<d;j++)
                    if((opp[j][0]==a && opp[j][1]==b)||(opp[j][0]==b && opp[j][1]==a))
                    {
                        seq.clear();
                        break;
                    }
            }
    }
    for(int i=0;i<seq.size();i++)
    {
        if(i>0)
            cout << ", ";
        cout << seq[i];
    }

}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #"<<i<<": [";
        tst();
        cout << "]\n";
    }

}
