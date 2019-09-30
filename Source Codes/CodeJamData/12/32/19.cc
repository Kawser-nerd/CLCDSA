#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

template <class T>
void read_nums(istream& ist, vector<T>& nums, size_t cnt){
    for(size_t i = 0; i < cnt; i++){
        T val;
        ist >> val;
        nums.push_back(val);
    }
}


double solve(double distance, vector<pair<double, double> >& positions, double acceleration){
    //cout << distance << ", " << acceleration << endl;
    double base_time = sqrt(2.0 * distance / acceleration);
    double max_wait = 0.0;
    double last_t = 0.0;
    double last_x = 0.0;
    for(size_t i = 0; i < positions.size(); i++){
        double t = positions[i].first;
        double x = positions[i].second;
        bool break_flag = false;
        if(x > distance){
            break_flag = true;
            t = last_t + (t - last_t) * (distance - last_x) / (x - last_x);
            x = distance;
        }
        double wait_time = max(0.0, t - sqrt(2.0 * x / acceleration));
        max_wait = max(max_wait, wait_time);
        last_t = t;
        last_x = x;
        if(break_flag) break;
    }
    return base_time + max_wait;
}

int main(){
    size_t T = 0;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        double D;
        int N, A;
        cin >> D >> N >> A;
        vector<pair<double, double> > positions;
        for(int n = 0; n < N; n++){
            double t, x;
            cin >> t >> x;
            positions.push_back(pair<double,double>(t, x));
        }
        vector<double> accelerations;
        read_nums(cin, accelerations, A);
        cout << "Case #" << t << ":" << endl;
        for(size_t a = 0; a < A; a++){
            double result = solve(D, positions, accelerations[a]);
            cout << setprecision(12) << result << endl;
        }
    }
    return 0;
}

