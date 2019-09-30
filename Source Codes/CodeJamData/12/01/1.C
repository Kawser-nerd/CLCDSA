#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<fstream>
#include<iostream>
#include<bitset>
#include<cassert>
#include<climits>
#include<vector>
#include<queue>
#include<string>

using namespace std;

char table[27] = "yhesocvxduiglbkrztnwjpfmaq";

void do_case(void)
{
    string in;
    getline(cin, in);
    for(int i = 0; i < in.length(); ++i) {
        if(in[i] == ' ')
            cout << ' ';
        else {
            cout << table[in[i] - 'a'];
        }
    }
    cout << '\n';
}

int main()
{
    freopen("input.data", "r", stdin);
    //freopen("output.data", "r", stdout);

    int cases;
    scanf("%d\n", &cases);
    int i = 1;
    do{
        printf("Case #%d: ", i);
        do_case();
    }while(++i <= cases);

    return 0;
}
