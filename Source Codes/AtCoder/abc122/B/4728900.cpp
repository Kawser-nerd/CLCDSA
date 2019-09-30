#include <iostream>
using namespace std;
int main(void){
    int count = 0;
    int max = 0;
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T'){
            count++;
            if(max < count)
                max = count;
        }else{
            count = 0;
        }
    }
    cout << max << endl;
    return 0;
}