#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int pos = 0;
    int num = 0;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 65){
            pos = i;
            break;
        }
    }

    int num2 = 0;

    for (int i = pos; i < s.size(); i++){
        num++;
        if (s[i] == 90){
            if (num > num2){
                num2 = num;
            }
        }
    }

    cout << num2 << endl;
    return 0;
}