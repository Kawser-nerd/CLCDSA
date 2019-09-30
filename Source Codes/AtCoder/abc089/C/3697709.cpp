#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> count(5, 0);
    int n;
    long long answer, tmp;
    answer = 0;
    bitset<5> b;
    string name;
    
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> name;
        if(name[0] == 'M'){
            count[0]++;
        }
        else if(name[0] == 'A'){
            count[1]++;
        }
        else if(name[0] == 'R'){
            count[2]++;
        }
        else if(name[0] == 'C'){
            count[3]++;
        }
        else if(name[0] == 'H'){
            count[4]++;
        }
    }
    for(int i=0; i<32; ++i){
        b = static_cast<bitset<5>>(i);
        if(b.count() != 3){
            continue;
        }
        else {
            tmp = 1;
            for(int j=0; j<5; ++j){
                if(b[j] == 1){
                    tmp *= count[j];
                }
            }
            answer += tmp;
        }
    }
    cout << answer << endl;
}