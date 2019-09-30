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
    cin >> s;
    long long answer = s.size() * (s.size() - 1) / 2;
    //cout << "first answer:" << answer << endl;

    for (char i = 'a'; i <= 'z'; i++)
    {
        long long count = 0;
        for (int j = 0; j < s.size();j++){
            if(s[j]==i){
                count++;
            }
        }
            answer -= count * (count - 1) / 2;
    }
    cout << answer+1 << endl;

    return 0;
}