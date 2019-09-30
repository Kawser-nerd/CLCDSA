#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

typedef long long int Int;

bool field[100][100];

int main(void) {
    int a,b;
    cin>>a>>b;

    for(int i = 50;i < 100;i++) {
        for(int j = 0;j < 100;j++) {
            field[i][j] = true;
        }
    }

    a--,b--;

    cout<<100<<" "<<100<<endl;

    for(int i = 0;i < 50;i += 2) {
        for(int j = 0;j < 100;j += 2) {
            if(b > 0) {
                b--;
                field[i][j] = true;
            }
        }
    }

    for(int i = 51;i < 100;i += 2) {
        for(int j = 0;j < 100;j += 2) {
            if(a > 0) {
                a--;
                field[i][j] = false;
            }
        }
    }

    for(int i = 0;i < 100;i++) {
        for(int j = 0;j < 100;j++) {
            if(field[i][j])
                cout<<"#";
            else
                cout<<".";
        }
        cout<<endl;
    }

    return 0;
}