#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        int x=n;
        for(int j=1;j<=n;j++)
        {
            int d;
            cin >> d;
            if(d==j)
                x--;
        }
        cout << "Case #"<<i<<": "<<x<<endl;
    }

}

