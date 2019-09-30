#include <iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    string s,t,temp;
    int i,j,k;
    cin>>s>>t;
    set<int> sett[2];
    for(i=0;i<s.size();i++)
    {
        sett[0].insert(s[i]);
        sett[1].insert(t[i]);
    }
    if(sett[1].size() != sett[0].size())
    {
        printf("No\n");
        return 0;
    }
    temp = s;
    int len = s.size();i=0;
    char ch ;
    while(temp != t && i<len)
    {
        ch = temp[len-1];
        temp = temp.substr(0,len-1);
        temp=ch+temp;
       // cout<<temp<<endl;
        i++;
    }
    if(i<len)
    {
        printf("Yes\n");
    }
    else {
        printf("No");
    }
    return 0;
}