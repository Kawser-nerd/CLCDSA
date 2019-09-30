#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> d;
vector<long long> p;

void init_v(int digit) {
        for(int i = 0;i < digit; i++) {
                long long num = (1LL << i);
                if(i % 2 == 1) num *= -1;
                p.push_back(num);
                if(i >= 2) num += d[i - 2];
                d.push_back(num);
        }

}

int get_digit(long long num) {
        for(int i = 0 ;i < d.size(); i++) {
                if(num > 0 && d[i] >= num) return i;
                if(num < 0 && d[i] <= num) return i;
        }
        return -1;
}
int main() {
        long long num;
        cin >> num;
        string s;
        if(num == 0) s = "0";
        while(num != 0) {
                int r = num % (-2);
                if( r < 0) r += 2;
                s = to_string(r) + s;
                num = (num - r) / -2;
        }
        cout << s << endl;
}