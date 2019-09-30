#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define DIFF ('a' - 'A')

int main(){
    string s;
    cin >> s;
    if(s[0] >= 'a') s[0] -= DIFF;
    printf("%c", s[0]);
    for(int i = 1; i < s.size(); ++i){
        if('A' <= s[i] && 'Z' >= s[i]){
            s[i]+=DIFF;
            
        }
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}