#include <iostream>
using namespace std;

int s[100009] = {0};
int n;
int main(){
    cin >> n;
    for(int i = 0 ; i < n; ++i){
        int a;
        scanf("%d", &a);
        s[max(0, a-1)]++;
        s[a+2]--;
    }
    for(int i = 0; i < 100003; ++i){
        s[i+1] = s[i+1]+s[i];
    }
    int maxI = 0;
    int index = 0;
    for(int i = 0; i < 100003; ++i){
        if(maxI < s[i]){
            maxI = s[i];
            index = i;
        }
    }

    cout << maxI << endl;
    return 0;

}