#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int s;
    int n,m;
    cin >> s;
    vector<int> retu;
    retu.push_back(s);
    int flag = 0;
    int i = 0;
    while (flag == 0){
        if (retu[i] % 2 == 0){
            retu.push_back(int(retu[i]/2));
        }
        else{
            retu.push_back(3 * retu[i] + 1);
        }
        i = i + 1;
        for (int j = 0;j < i;j++){
            if (retu[i] == retu[j]){
                flag = 1;
                n = retu[j];
                m = i + 1;
            }
        }
    } 
    cout << m << endl;

}