#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;

int main(void){
    std::string s;
    int K;
    cin >> s;
    cin >> K;
    std::vector< std::string > strlist;
    //cout << "initialize finished" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        
        for (int j = 0; j < 5 && i + j < s.size();j++)
        {
            std::string push_str;
            for (int k = i; k <= i + j;k++)
            {
                push_str += s[k];
            }
            strlist.push_back(push_str);
        }
        
    }
    //cout << "push finished" << endl;
    std::sort(strlist.begin(), strlist.end());
    //cout << "sort finished----" << endl;
    /*for(auto x:strlist){
        cout << x << endl;
    }*/
    //cout << "----" << endl;
    int rank = 0;
    int pos = 0;
    std::string prev_str = "1";
    while (rank < K)
    {
        if(prev_str!=strlist[pos]){
            rank++;
        }
        prev_str = strlist[pos];
        //cout << prev_str << endl;
        pos++;
    }

    cout << prev_str << endl;

    return 0;
}