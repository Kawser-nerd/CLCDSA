#include <iostream>
#include <string>

int main() {
    int h,w;
    std::cin >> h >> w;
    std::string s[50];
    
    for(int i = 0; i < h; i++) std::cin >> s[i];

    int dx[8] = {0,0,1,1,1,-1,-1,-1};
    int dy[8] = {1,-1,0,1,-1,0,1,-1};

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') continue;
            int num = 0;
            for(int k = 0; k < 8; k++){
                if(i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w)continue;
                else if(s[i + dy[k]][j + dx[k]] == '#') num++;
            }
            s[i][j] = (char)(num + '0');
        }
    }
    for(int i = 0; i < h; i++) std::cout << s[i] << std::endl;
}