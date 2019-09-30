#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    int flag = 1;
    for(int i = 0; i < len;){
        if(flag == 0)break;
        int flagd1 = 0, flagd2 = 0;
        int flage1 = 0, flage2 = 0;
        if(s[i] == 'd'){
            if(i+5 <= len){
                if(s.substr(i, 7)=="dreamer"){
                    flagd2 = 1, i+=7;
                    if(s.substr(i-2, 5)=="erase"){
                        flagd1 = 1, i-=2;
                        continue;
                    }
                }
                else {
                    if(s.substr(i, 5)=="dream")flagd1 = 1, i+=5;
                }
            }
            if(flagd1 || flagd2)continue;
            else {
                flag = 0;
                break;
            }
        }
        else if(s[i] == 'e'){
            if(i+5 <= len){
                if(s.substr(i, 6)=="eraser")flage2 = 1, i+=6;
                else {
                    if(s.substr(i, 5)=="erase")flage1 = 1, i+=5;
                }
            }
            if(flage1 || flage2)continue;
            else {
                flag = 0;
                break;
            }
        }
        else {
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}