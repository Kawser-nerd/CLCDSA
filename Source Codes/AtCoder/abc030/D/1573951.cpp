#include <iostream>
#include <vector>
#include <string>
#define MAX_N 100000
using namespace std;

int N, a;
string s;

int b[MAX_N+1], c[MAX_N+1] = {0};
vector<int> v;

int main(){
    cin >> N >> a >> s;
    for(int i = 1; i <= N; ++i) cin >> b[i];
    int i = a;
    int base = 0;
    int loop = 1;
    while(1){
        if(c[i]){
            int tmp = i;
            i = a;
            while(i != tmp){
                i = b[i];
                base++;
            }
            i = b[tmp];
            while(i != tmp){
                v.push_back(i);
                i = b[i];
                loop++;
            }
            v.push_back(i);
            break;
        }
        c[i] = 1;
        i = b[i];
    }

    if(s.size() < 9){
        int tmp = stoi(s);
        if(base >= tmp){
            cout << b[tmp] << endl;
            return 0;
        }
    }
    base = -base + loop * (base / loop + 1);
    int modSum = 0;
    i = 1;

    while(s.size()){
        int num = s[s.size()-1] - '0';
        s.pop_back();
        modSum = (modSum + num * i % loop) % loop;
        i = i * 10 % loop;
    }
    
    modSum = modSum + base % loop <= 0 ? loop : modSum + base % loop;
    modSum %= loop;
    cout << v[(modSum+loop-1)%loop] << endl;

    return 0;
}