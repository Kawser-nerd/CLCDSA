#include<iostream>

using namespace std;

int main() {
    int h , w;
    cin >> h >> w;
    char a[11][11];
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            a[i][j] = '.';
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    a[0][0] = '.';
    for(int i = 0, j = 0;;) {
        if(i == h -1 && j == w - 1){
            break;
        }

        //if(a[i+1][j] == '#' && a[i][j+1] == '#') {

            //cout << "Impossible" << endl;
            //return 0;
        if(a[i+1][j] == '.' && a[i][j+1] == '.'){
            cout << "Impossible" << endl;
            return 0;
        }
        if(a[i+1][j] == '#') {
            a[i+1][j] = '.';
            i++;
            continue;
        }
        if(a[i][j+1] == '#') {
            a[i][j+1] = '.';
            j++;
            continue;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    return 0;
}