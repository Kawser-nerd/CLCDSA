#include <iostream>
#include <vector>

using namespace std;


int main()
{

        int n, input;
        vector<int> p;
        int high = 0;
        int am = 0;

        cin >> n;

        for (int i=0; i<n; i++) {
                cin >> input;

                if (input > high) {
                        p.push_back(high);
                        high = input;
                } else {
                        p.push_back(input);
                }
        }

        for (auto i : p) {
                am += i;
        }
        am += high / 2;

        cout << am << endl;


        return 0;
}