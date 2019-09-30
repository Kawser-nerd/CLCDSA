#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec1 {1, 3, 5, 7, 8, 10, 12};
    std::vector<int> vec2 {4, 6, 9, 11};
    std::vector<int> vec3 {2};

    int x, y;
    std::cin >> x >> y;

    bool flg = false;
    if(vec1.end() !=  std::find(vec1.begin(), vec1.end(), x)){
        if(vec1.end() !=  std::find(vec1.begin(), vec1.end(), y)){
            flg = true;
        }
    }else if(vec2.end() !=  std::find(vec2.begin(), vec2.end(), x)){
        if(vec2.end() !=  std::find(vec2.begin(), vec2.end(), y)){
            flg = true;
        }
    }else if(vec3.end() !=  std::find(vec3.begin(), vec3.end(), x)){
        if(vec3.end() !=  std::find(vec3.begin(), vec3.end(), y)){
            flg = true;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}