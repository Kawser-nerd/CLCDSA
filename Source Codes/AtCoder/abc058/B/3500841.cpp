#include <iostream>
#include <string>
using namespace std;
int main(){
    string e,o;
     cin >> e >> o;
    for(int i=0;e[i]!='\0'||o[i]!='\0';i++){
            if(e[i]!='\0')
                cout << e[i];
            if(o[i]!='\0')
                cout << o[i];
        }
        cout << endl;

return 0;

}