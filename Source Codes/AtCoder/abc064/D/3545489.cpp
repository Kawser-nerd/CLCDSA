#include <iostream>
#include <string>

using namespace std;

int main(){
    
    // N : length of the string
    // S : string itself ()(((()()

    long N;
    string S;
    
    scanf("%ld", &N);
    cin >> S;
    char c;
    
    long cnt = 0;
    string ans = S;
    
    
    for(unsigned long i = 0; i<N; i++) {
        c = S[i];
        if(c=='('){
            cnt += 1;
        } else {
            cnt -= 1;
            if(cnt < 0){
                ans = '('+ans;
                cnt += 1;
            }
        }
    }
    
    
    for(long i = 0; i< cnt; i++){
        ans = ans+')';
    }
    
    cout << ans << endl;
    
    
    return 0;
}