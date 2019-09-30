#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
    int D, G;
    cin >> D >> G;
    vector<int> p, c;
    for (size_t i = 0; i < D; i++) {
        int pp, cc;
        cin >> pp >> cc;
        p.push_back(pp);
        c.push_back(cc);
    }

    vector<int> result;

    unsigned get_bounus_flag = 0;

    while(true) {



        int point_sum = 0;
        int solve_num = 0;

        for (size_t i = 0; i < D; i++) {
            if((get_bounus_flag >> i) & 1) {
                point_sum += c.at(i) + p.at(i) * 100*(i+1);
                solve_num += p.at(i);
            }
        }

        if(point_sum < G) {
            for (int i = D-1; i >= 0; i--) {
                if((get_bounus_flag >> i) & 1) {
                    continue;
                }

                int all_point = (p.at(i)-1) * 100*(i+1);
                if( all_point + point_sum >= G ) {
                    int n = (G - point_sum) / (100*(i+1));
                    if( n * 100*(i+1) + point_sum < G) {
                        n += 1;
                    }
                    solve_num += n;
                    point_sum += n * 100*(i+1);
                    break;
                } else {
                    solve_num += p.at(i) - 1;
                    point_sum += all_point;
                }
            }
        }

        if(point_sum >= G) {
            result.push_back(solve_num);
        }


        get_bounus_flag++;
        if(get_bounus_flag / pow(2, D) == 1) {
            break;
        }
    }

    cout << *min_element(result.begin(), result.end()) << endl;
}