#include<iostream>
#include <vector>

using namespace std;

int main() {



    // ????? ?????????????
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;


    int w_suger_water = 0;
    int w_suger = 0;



    std::vector<int> water_paterrn;
    for (int a = 1; a <= 30; a++) {
        for (int b = 0; b <= 30; b++) {

            int watter = ((a * A )+ (b * B)) * 100;
            if (watter < F && watter!=0) {

                water_paterrn.push_back(watter);
            }

        }

    }


/*
    for (const auto &p : water_paterrn) {

        cout << p << endl;
    }
*/

    std::vector<double> result;
    std::vector<pair<int, int>> finalresult;


    for (int i = 0; i < water_paterrn.size(); i++) {

        int enable_suger_max = (int) ((water_paterrn[i] / 100) * E);


        int allsuger = 0;
        int water_and_suger_mass = 0;//water_paterrn[i];
        double concentration = 0;
        //
        double max_concentration = 0;
        int max_allsuger = 0;
        int max_water_and_suger = 0;

        for (int iter_c = 0; iter_c <= enable_suger_max; iter_c++) {

            for (int iter_d = 0; iter_d <= enable_suger_max; iter_d++) {

                allsuger = (iter_c * C) + (iter_d * D);
                water_and_suger_mass = water_paterrn[i] + allsuger;

                if ((water_and_suger_mass <= F ) && ( enable_suger_max >= allsuger) && (water_and_suger_mass !=0)) {

                    double j=allsuger;
                    double k=water_and_suger_mass;
                    concentration = (100.0*j)/k;

                    if (concentration >= max_concentration) {
                        max_concentration = concentration;
                        max_allsuger = allsuger;
                        max_water_and_suger = water_and_suger_mass;
                    }

                }
            }

        }

        result.push_back(max_concentration);
        finalresult.emplace_back(max_water_and_suger, max_allsuger);
    }

    //
    std::vector<double >::iterator iter2 = std::max_element(result.begin(), result.end());
    size_t index2 = static_cast<size_t>(std::distance(result.begin(), iter2));


    w_suger_water = finalresult[index2].first;
    w_suger = finalresult[index2].second;


// ??
    cout << w_suger_water << " " << w_suger << endl;
    return 0;
}