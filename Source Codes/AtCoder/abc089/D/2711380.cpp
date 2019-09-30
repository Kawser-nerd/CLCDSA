#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class nv {
public:
    int a;
    int x,y;
    bool operator < (const nv& obj) const{
        return a < obj.a;
    }
};

int h,w,d,q;
unsigned long long int s[300*300 + 1];
vector<nv> p;

void input() {
    nv temp;
    cin >> h >> w >> d;
    for(int y = 0;y < h;y++) {
        for(int x = 0;x < w;x++) {
            cin >> temp.a;
            temp.x = x;
            temp.y = y;
            p.push_back(temp);
        }
    }
    cin >> q;
}

void prepare_query(void) {
    sort(p.begin(), p.end());
    for(int i = 1;i <= d;i++) {
        for(int ii = i + d;ii <= h * w;ii = ii + d) {
            nv cmp;
            cmp.a = ii - d;
            auto i_b = lower_bound(p.begin(), p.end(), cmp);
            cmp.a = ii;
            auto i_a = lower_bound(p.begin(), p.end(), cmp);
            s[ii] = s[ii - d] + abs(i_a->x - i_b->x) + abs(i_a->y - i_b->y);
        }
    }
}

unsigned long long int proc_query(int l,int r) {
    return s[r] - s[l];
}

int main(void) {
    input();
    prepare_query();
    int l,r;
    for(int i = 0;i < q;i++) {
        cin >> l >> r;
        cout << proc_query(l, r) << endl;
    }
}