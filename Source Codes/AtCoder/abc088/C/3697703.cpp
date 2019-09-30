#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<int>> c;
    int sum = 0;
    int s;
    bool b = true;
    c.resize(4);
    for(int i=1; i<=3; ++i){
        c[i].resize(4);
        cin >> c[i][1] >> c[i][2] >> c[i][3];
    }
    for(int i=1; i<=3; ++i){
        for(int j=1; j<=3; ++j){
            sum += c[i][j];
        }
    }
    if(sum % 3 == 0){
        for(int i=0; i<6; ++i){
            switch(i){
                case 0:
                    s = c[1][1] + c[2][2] + c[3][3];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
                case 1:
                    s = c[1][2] + c[2][3] + c[3][1];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
                case 2:
                    s = c[1][3] + c[2][1] + c[3][2];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
                case 3:
                    s = c[1][1] + c[2][3] + c[3][2];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
                case 4:
                    s = c[1][2] + c[2][1] + c[3][3];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
                case 5:
                    s = c[1][3] + c[2][2] + c[3][1];
                    if(3 * s != sum){
                        b = false;
                    }
                    break;
            }
            if(!b){
                break;
            }
        }
        if(b){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}