#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
#define  ll  long long;

int main() {
        int n,k;
        cin >> n >> k;

        int min_suki;

        int d[10];
        for (int i = 0; i < 10; i++) {
                d[i] = 0;
        }
        for (int i = 0; i < k; i++) {
                int kirai;
                cin >> kirai;
                d[kirai] = 1;
        }

        for (int i = 0; i < 10; i++) {
                if (d[i] == 0) {
                        min_suki = i;
                        break;
                }
        }


        int nKeta[5];
        int keta_s = -1;
        int num = n;
        int ans;
        for (int i = 0; i < 5; i++) {
                nKeta[i] = 0;
        }

        for (int i = 3; i >= 0; i--) {
                nKeta[i] = num / pow(10,i);
                if (nKeta[i] != 0 && keta_s == -1) {
                        keta_s = i;
                }
                num = num - nKeta[i] * pow(10,i);
        }

        while(true) {
                ans = 0;
                for (int i = keta_s; i >= 0; i--) {
                        //cout << "nKeta[3]:" << nKeta[3] << endl;
                        for (int j = 0; j < 10; j++) {
                                if(nKeta[i] < j && d[j] == 0) {
                                        ans += j * pow(10,i);
                                        for (int k = 0; k < i; k++) {
                                                ans += min_suki * pow(10,k);
                                        }
                                        cout << ans << endl;
                                        return 0;
                                }
                                else if (nKeta[i] == j && d[j] == 0 ) {
                                        if (i == keta_s && j == 0){
                                                continue;
                                        }
                                        //cout << j << endl;
                                        ans += j * pow(10,i);
                                        break;
                                }
                        }
                }
                //cout << "ans:" << ans << endl;
                if (n > ans) {
                        keta_s++;
                        //cout << "increase keta" << endl;
                        //cout << "keta_s:" << keta_s << endl;
                }
                else {
                        //cout << "break" << endl;
                        break;
                }
        }
        cout << ans << endl;
        return 0;
}