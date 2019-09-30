#include<iostream>
#include <string>
using namespace std;

/*
int main() {
    string s;
    int n;
    string a[2];
    cin >> s >> n;
    if (n >= 1 && n <= 5){a[0] = s[0];}
    if (n >= 6 && n <= 10){a[0] = s[1];}
    if (n >= 11 && n <= 15){a[0] = s[2];}
    if (n >= 16 && n <= 20){a[0] = s[3];}
    if (n >= 21 && n <= 25){a[0] = s[4];}
    if (n % 5 == 0){a[1] = s[0];}
    if (n % 5 == 1){a[1] = s[1];}
    if (n % 5 == 2){a[1] = s[2];}
    if (n % 5 == 3){a[1] = s[3];}
    if (n % 5 == 4){a[1] = s[4];}
    cout << a << endl;
}
 */

int main(){
    string s;
    int n;
    int cnt = 0;
    cin >> s >> n;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cnt ++;
            if(cnt == n){
                cout << s[i] << s[j] << endl;
                return 0;
            }
        }
    }

}