#include<algorithm>  
#include<iostream>  
#include<cstdio>  
#include<map>  
#include<set>  
using namespace std;  
string s, t;  
set<string> S;  
  
void Work()  
{  
    int lens = s.size();  
    int lent = t.size();  
    for(int i = 0; i < lens; i++)  
    {  
        if(s[i] == '?' || s[i] == t[0])//??????  
        {  
            string tmp = s;              //???????????  
            for(int j = 0; j < i; j++)  
                if(tmp[j] == '?')  
                    tmp[j] ='a';      
            bool can = false;  
            for(int j = 0; j < lent; j++)    //???????  
            {  
  
                if(tmp[i+j]!= '?' && tmp[i+j] != t[j])  //????  
                    break;  
                tmp[i+j] = t[j];  
                if(j == lent - 1) can = true;  
            }  
            if(can)  
            {  
                for(int j = i + lent; j < lens; j++) if(tmp[j] == '?') tmp[j] = 'a';//????????  
                S.insert(tmp);  //????  
            }  
        }  
    }  
    if(S.size() == 0) cout << "UNRESTORABLE" << endl;  
    else cout << *S.begin() << endl;  
}  
int main()  
{  
    cin >> s >> t;  
    Work();  
}