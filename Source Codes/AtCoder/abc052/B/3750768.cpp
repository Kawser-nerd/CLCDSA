#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    int x = 0;
    int Max = 0;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 73){
            x++;
        }else if (s[i] == 68){
            x--;
        }

        if (x > Max){
            Max = x;
        }
    }

    cout << Max << endl;
}