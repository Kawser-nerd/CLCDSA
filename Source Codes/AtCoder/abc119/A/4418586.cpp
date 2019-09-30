#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main(void) {
    int y,m,d;
    char tmp;
    cin >> y;
    cin >> tmp;
    cin >> m;
    cin >> tmp;
    cin >> d;

    auto t1 = ptime(date(y,m,d));
    auto t2 = ptime(date(2019,4, 30));
    auto duration = t2 - t1;
    // cout << "[DEBUG] " << duration << endl;
    
    if (duration .ticks() >= 0) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }
    return 0;
}