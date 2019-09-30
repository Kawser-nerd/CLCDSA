#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[123][123];
int rmax[123], cmax[123];

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int N, M;
        cin>>N>>M;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<N; i++)
        {
            rmax[i] = -1;
            for(int j=0; j<M; j++)
            {
                rmax[i] = max(rmax[i], arr[i][j]);
            }
        }
        for(int j=0; j<M; j++)
        {
            cmax[j] = -1;
            for(int i=0; i<N; i++)
            {
                cmax[j] = max(cmax[j], arr[i][j]);
            }
        }
        bool ok = true;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(arr[i][j]!=rmax[i] && arr[i][j]!=cmax[j])ok = false;
            }
        }
        cout<<"Case #"<<t<<": "<<(ok ? "YES" : "NO")<<endl;
    }

    return 0;
}
