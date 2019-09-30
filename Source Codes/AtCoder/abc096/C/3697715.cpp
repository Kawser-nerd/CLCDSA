#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

vector<string> g;
int h, w;

bool check(int i, int j){
    if(i > 0 && g[i-1][j] == '#'){
        return true;
    }
    else if(j < w-1 && g[i][j+1] == '#'){
        return true;
    }
    else if(i < h-1 && g[i+1][j] == '#'){
        return true;
    }
    else if(j > 0 && g[i][j-1] == '#'){
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    cin >> h >> w;
    string answer = "Yes";
    g.resize(h);
    for(int i=0; i<h; ++i){
        cin >> g[i];
    }
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(g[i][j] == '.'){
                continue;
            }
            else if(g[i][j] == '#'){
                if(!check(i, j)){
                    answer = "No";
                }
            }
        }
    }
    cout << answer << endl;
}