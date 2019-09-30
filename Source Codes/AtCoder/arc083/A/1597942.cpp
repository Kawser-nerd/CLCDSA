#include <iostream>
using namespace std;

double a, b, c, d, e, f;

int main(){
    double max = -1;
    double water = 0;
    double sugar = 0;
    cin >> a >> b >> c >> d >> e >> f;
    for(double i = 0; i < f / (a * 100); ++i)
    for(double j = 0; j < f / (b * 100); ++j)
    for(double k = 0; k < f / c; ++k)
    for(double l = 0; l < f / d; ++l){
        if(100*(a*i+b*j)+c*k+d*l > f) continue;
        double tmp = (double)(100 * (c*k+d*l) / (100*(a*i+b*j) + (c*k+d*l)));
        if(tmp > 100* e / (100+e)) continue;
        if(max < tmp){
            max = tmp;
            water = (a*i+b*j)*100;
            sugar = c*k+d*l;
            
        }
    }

    cout << water + sugar << " " <<  sugar << endl;

    return 0;
}