#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> box(n);
    vector<int> tower;
    for (int i=0; i<n; ++i){
        cin >> box[i];
    }
    for (int i=0; i<n; ++i){
        if(i == 0){
            tower.push_back(box[i]);
        }
        else {
            bool check = false;
            for (int j=0; j<(int)tower.size(); ++j){
                if (tower[j] >= box[i]){
                    tower[j] = box[i];
                    check = true;
                    break;
                }
            }
            if(!check){
                tower.push_back(box[i]);
            }
        }
    }
    cout << tower.size() << endl;
    return 0;
}