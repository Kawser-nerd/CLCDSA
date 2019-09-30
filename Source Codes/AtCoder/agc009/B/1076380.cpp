#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int N;
int A[100010];
std::vector<std::vector<int>> win;

int dfs(int pos) {
    if(win[pos].size() == 0) {
        return 0;
    }
    
    std::vector<int> height;
    height.reserve(win[pos].size());
    
    for(auto& w : win[pos]) {
        height.push_back(dfs(w));
    }
    std::sort(height.begin(), height.end(), std::greater<int>());
    
    for(int i = 0; i < height.size(); ++i) {
        height[i] += i + 1;
    }
    
    return *std::max_element(height.begin(), height.end());
}

int main() {
    std::cin >> N;
    
    win.resize(N);
    for(int i = 1; i < N; ++i) {
        std::cin >> A[i];
        --A[i];
        win[A[i]].push_back(i);
    }
    
    std::cout << dfs(0) << std::endl;
}