#include <iostream>

using namespace std;

long diff(long a, long b, long c){
    long m = min(a, min(b, c));
    long M = max(a, max(b, c));
    return M-m;
}

int main(){
    long H, W;
    cin >> H >> W;
    if(H%3 == 0 || W%3 == 0){
        cout << 0 << endl;
    }else{
        long ans = abs(H*(W/3)-H*(W/3+1));
        ans = min(ans, abs(W*(H/3)-W*(H/3+1)));
        if(H%2 == 0){
            long a = (H/2)*(W-W/3);
            long b = H*(W/3);
            ans = min(ans, abs(a-b));
            a = (H/2)*(W-W/3-1);
            b = H*(W/3+1);
            ans = min(ans, abs(a-b));
        }else{
            long a = (H/2)*(W-W/3);
            long b = H*(W/3);
            long c = (H/2+1)*(W-W/3);
            ans = min(ans, diff(a, b, c));
            a = (H/2)*(W-W/3-1);
            b = H*(W/3+1);
            c = (H/2+1)*(W-W/3-1);
            ans = min(ans, diff(a, b, c));
        }
        if(W%2 == 0){
            long a = (W/2)*(H-H/3);
            long b = W*(H/3);
            ans = min(ans, abs(a-b));
            a = (W/2)*(H-H/3-1);
            b = W*(H/3+1);
            ans = min(ans, abs(a-b));
        }else{
            long a = (W/2)*(H-H/3);
            long b = W*(H/3);
            long c = (W/2+1)*(H-H/3);
            ans = min(ans, diff(a, b, c));
            a = (W/2)*(H-H/3-1);
            b = W*(H/3+1);
            c = (W/2+1)*(H-H/3-1);
            ans = min(ans, diff(a, b, c));
        }
        cout << ans << endl;
    }
}