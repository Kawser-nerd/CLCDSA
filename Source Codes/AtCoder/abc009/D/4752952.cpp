#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T[33][100][100];

int main()
{
    int K, M;
    cin >> K >> M;
    unsigned int ans;
    vector<unsigned int> A;
    vector<unsigned int> C;
    A.resize(K);
    C.resize(K);
    for (int i = 0; i < K; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < K; i++)
    {
        cin >> C[i];
    }
    if(M <= K)
    {
        ans = A[M-1];
    }
    else
    {
        reverse(A.begin(), A.end());
        M -= K;
        for (int i = 0; i < K;i++)
        {
            for (int j = 0; j < K;j++)
            {
                if(i == 0)
                {
                    T[1][0][j] = C[j];
                }
                else
                {
                    T[1][i][j] = (i - 1 == j ? -1 : 0);
                }
                //cout << T[1][i][j] << " ";
            }
            //cout << endl;
        }
        for (int i = 1; i < 32;i++)
        {
            for (int j = 0; j < K;j++)
            {
                for (int k = 0; k < K;k++)
                {
                    int t = 0;
                    for (int l = 0; l < K; l++)
                    {
                        t ^= T[i][k][l] & T[i][l][j];
                    }
                    T[i + 1][k][j] = t;
                }
            }
        }
        for (int i = 1; i <= 32; i++)
        {
            int v[101];
            //cout << "A[" << 1 << "] = " << A[1] << endl;
            if (M & (1 << (i - 1)))
            {
                //cout << "i:" << i << endl;
                for (int j = 0; j < K; j++)
                {
                    int t = 0;
                    for (int k = 0; k < K; k++)
                    {
                        t ^= T[i][j][k] & A[k];
                    }
                    v[j] = t;
                    //cout << "t:" << t << endl;
                }
                for (int j = 0; j < K;j++)
                {
                    A[j] = v[j];
                }
            }
        }
        ans = A[0];
    }
    cout << ans << endl;
    return 0;
}