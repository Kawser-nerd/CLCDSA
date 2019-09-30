#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    vector<string> B(M);
    for(auto& e : A)
        cin >> e;
    for(auto& e : B)
        cin >> e;


    for(int i = 0; i < N - M + 1; ++i)
    {
        auto pos = A[i].find(B[0]);
        if(string::npos != pos)
        {
            bool ans = true;
            for(int j = 1; j < M; ++j)
            {
                if(A[i + j].substr(pos, M) != B[j])
                {
                    ans = false;
                    break;
                }
            }
            if(ans)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}