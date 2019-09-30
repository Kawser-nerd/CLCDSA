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

int test_pos(int t, int p)
{
    switch(t % 3) {
    case 0:
        if(t == 0)
            return 0;
        else 
            return t / 3 + 1 == p;
    case 1:
        return 0;
    case 2:
        return t / 3 + 2 == p;
    default:
        cerr << "Something funny happened.\n";
        return 0;
    }
}

int test_def(int t, int p)
{
    switch(t % 3) {
    case 0:
        return t / 3 >= p;
    case 1:
        return t / 3 + 1 >= p;
    case 2:
        return t / 3 + 1 >= p;
    default:
        cerr << "Something funny happened.\n";
        return 0;
    }
}

void do_case(void)
{
    int N, S, p;
    cin >> N >> S >> p;

    int possible = 0;
    int definitely = 0;
    for(int i = 0; i < N; ++i) {
        int t;
        cin >> t;

        possible += test_pos(t, p);
        definitely += test_def(t, p);
    }
    if(possible > S) possible = S;
    cout << definitely + possible << endl;
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
