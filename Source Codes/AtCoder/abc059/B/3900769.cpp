#include <iostream>

using namespace std;

int main(void)
{
    string A, B;
    cin >> A >> B;

    if(A.size() > B.size())
    {
        cout << "GREATER" << endl;
        return 0;
    }
    else if(A.size() < B.size())
    {
        cout << "LESS" << endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] > B[i])
            {
                cout << "GREATER" << endl;
                return 0;
            }
            else if(A[i] < B[i])
            {
                cout << "LESS" << endl;
                return 0;
            }
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}