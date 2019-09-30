#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    std::vector<std::string> b(m);
    for(int i = 0; i < m; ++i){
        std::cin >> b.at(i);
    }

    int counter;
    bool flg = false;
    for(int i = 0; i <= n - m; ++i){
        for(int j = 0; j <= n - m; ++j){
            counter = 0;
            for(int k = i; k < i + m; ++k){
                for(int l = j; l < j + m; ++l){
                    if(a.at(k).at(l) == b.at(k - i).at(l - j)){
                        ++counter;
                    }
                }
            }
            
            if(m*m == counter){
                flg = true;
                break;
            }
        }
        
        if(m*m == counter){
            flg = true;
            break;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}