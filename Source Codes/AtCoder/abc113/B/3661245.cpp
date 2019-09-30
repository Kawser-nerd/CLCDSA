#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int t, a;
    scanf("%d%d", &t, &a);
    vector<float> temp;
    for (int i = 0; i < n; i++) {
       int d;
       scanf("%d", &d);
       temp.push_back(abs((t-d*0.006)-a));
    }
    vector<float>::iterator iter = min_element(temp.begin(), temp.end());
    size_t index = std::distance(temp.begin(), iter);
    printf("%ld\n", index+1);
    return 0;
}