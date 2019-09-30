#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> P;

int main(){
    long H, W, N;
    P xy[9];
    xy[0] = P(-1, -1), xy[1] = P(0, -1), xy[2] = P(1, -1);
    xy[3] = P(-1, 0), xy[4] = P(0, 0), xy[5] = P(1, 0);
    xy[6] = P(-1, 1), xy[7] = P(0, 1), xy[8] = P(1, 1);
    map<P, int> m;
    cin >> H >> W >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        for(int j = 0; j < 9; j++){
            if(a+xy[j].first >= 0 && a+xy[j].first < H && b+xy[j].second >= 0 && b+xy[j].second < W){
                if(m.count(P(a+xy[j].first, b+xy[j].second)) == 0){
                    m[P(a+xy[j].first, b+xy[j].second)] = 1;
                }else{
                    m[P(a+xy[j].first, b+xy[j].second)]++;
                }
            }
        }
    }
    long ans[10] = {0};
    ans[0] = (H-2)*(W-2);
    for(auto iter = m.begin(); iter!= m.end(); iter++){
        //cout << iter->first.first << ' ' << iter->first.second << ' ' << iter->second << endl;
        int x = iter->first.first;
        int y = iter->first.second;
        if(x > 0 && x < H-1 && y > 0 && y < W-1){
            ans[iter->second]++;
            ans[0]--;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << ans[i] << endl;
    }
}