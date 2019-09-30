#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    string flag = "NO";
    string str;
    str = to_string(n);
    int len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i] == '3'){
            flag = "YES";
            break;
        }
    }

    if(n % 3 == 0){
        flag = "YES";
    }

    cout << flag << endl;
    
    return 0;
}