#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    bool used[26];
    char p[26];
    string str;
    cin>>str;

    for(int i = 0;i < str.size();i++) {
        used[str[i] - 'a'] = true;
        p[i] = str[i];
    }

    if(str.size() == 26) {
        if(next_permutation(p,p+str.size())) {
            for(int i = 0;i < str.size();i++) {
                cout<<p[i];
                if(p[i] != str[i]) {
                    cout<<endl;

                    return 0;
                }
            }
        } else {
            cout<<-1<<endl;

            return 0;
        }
    }

    for(int i = 0;i < 26;i++) {
        if(used[i] == false) {
            str+= 'a' + i;

            break;
        }
    }

    cout<<str<<endl;

    return 0;
}