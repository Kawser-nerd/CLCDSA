#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int town;
    long long A, B;

    cin >> town >> A >> B;

    vector<long long> V;

    long long fatigue = 0;

    for (long long i = 0; i < town; i++){
        int x;
        cin >> x;
        V.push_back(x);
    }


    for (int i = 0; i < V.size()-1; i++){
        long long walk = A*abs(V[i]-V[i+1]);
        long long teleport = B;

        if (walk < teleport){
            fatigue += walk;
            continue;
        }else if (teleport < walk){
            fatigue += teleport;
            continue;
        }
    }

    cout << fatigue << endl;

    return 0;
}