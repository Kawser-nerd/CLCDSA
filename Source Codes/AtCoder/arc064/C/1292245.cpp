#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>      // std::setprecision
using namespace std;

int main(){
    int n;
    long long a, min_w, x1,y1,r1,x2,y2,r2,i,s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cin >> n;
    long long point[n+2][3];
    //cin >> point[0][0] >> point[0][1] >> point[n+1][0] >> point[n+1][1];
    point[0][0] = s1; point[0][1] = s2; point[n+1][0] = s3; point[n+1][1] = s4;
    point[0][2] = 0; point[n+1][2] = 0;
    for(i = 1; i< n+1; i++){
        cin >> point[i][0] >> point[i][1] >> point[i][2];
    }
    int chos;
    a = 0;
    int use[n+2];
    double weigth[n+2], dist;
    weigth[0] = 0;
    for(i = 1; i < n+2; i++) weigth[i] = pow(10,10);
    for(i = 1; i < n+2; i++) use[i] = 1;
    while (a != n+1){
        use[a] = 0;
        //cout << "a" << a << endl;
        chos = a;
        min_w = pow(10,10);
        x1 = point[chos][0];y1 = point[chos][1];r1 = point[chos][2];
        for (i = 0; i < n+2;i++){
            if (use[i] == 0) continue;
            x2 = point[i][0]; y2 = point[i][1]; r2 = point[i][2];
            dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2)) - (r1 + r2);
            if (dist < 0) dist = 0;
            if(dist + weigth[chos] < weigth[i]) weigth[i] = dist + weigth[chos];
            if(weigth[i] <= min_w){
                a = i;
                min_w = weigth[i];
            }
        }
    }
    cout << setprecision(11) << weigth[n+1] << endl;
    return 0;
}