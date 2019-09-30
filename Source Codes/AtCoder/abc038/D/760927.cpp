#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> box(262144);
vector<int> aCnt(262144);
int N;

void update(int k, int s){
    if (aCnt[k] < s) {
        aCnt[k] = s;
        if (k > 0) {
            update((k - 1) / 2, s);
        }
    }
}

int get(int l, int r, int k, int st, int ed){
    
    if (r <= st || ed <= l) {
        return 0;
    }
    if (l <= st && ed <= r) {
        return aCnt[k];
    }
    
    int md = (st + ed) / 2;
    return max(get(l, r, k*2+1, st, md), get(l, r, k*2+2, md, ed));
}

// w????h???
bool comp(const pair<int, int> &lhs,  const pair<int, int> &rhs) {
    return (lhs.first == rhs.first) ? (lhs.second > rhs.second) : (lhs.first < rhs.first);
}

int main()
{
    cin >> N;
    box.resize(N);
    
    for (int i = 0; i < N; i++) {
        int w, h;
        scanf("%d", &w);
        scanf("%d", &h);
        
        box[i] = make_pair(w, h);
    }
    
    for (int i = 0; i < 262144; i++) {
        aCnt[i] = 0;
    }
    
    sort(box.begin(), box.end(), comp);
    
    for (int i = 0; i < N; i++) {
        int s = get(0, box[i].second - 1, 0, 0, 131072);
        update(131071 + box[i].second - 1, s + 1);
    }
    
    cout << aCnt[0] << endl;
    
    return 0;
}