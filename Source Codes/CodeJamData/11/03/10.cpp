#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void tst()
{
    int n;
    cin >> n;
    vector<int> in(n);

    int x=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> in[i];
        x ^= in[i];
        sum += in[i];
    }
    sort(in.begin(),in.end());
    if(x)
        cout << "NO";
    else
        cout << sum - in[0];
    cout << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        tst();
    }
}
