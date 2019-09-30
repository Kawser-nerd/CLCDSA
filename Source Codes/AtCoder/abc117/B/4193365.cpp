#include <iostream>
using namespace std;
int main(void){
    int N, L[11];
    cin >> N;
    int longest = 0;
    for(int i=0; i<N; i++){
        cin >> L[i];
        longest = max(longest, L[i]);
    }
    int sum = 0;
    int count=0;
    for(int i=0; i<N; i++){
        if(L[i]==longest&&count==0) {
            count++;
            continue;
        }
        sum += L[i];
    }
    if(longest<sum){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}