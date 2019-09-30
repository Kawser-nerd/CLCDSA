#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using lli = long long int;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

lli median(lli x, lli y, lli z) {
    if (x < y) {
        if (y < z) { return y; }
        else if (z < x) { return x; }
        else { return z; }
    } else {
        if (z < y) { return y; }
        else if (x < z) { return x; }
        else { return z; }
    }
}

void quicksort(lli *a, lli left, lli right) {
    if (left < right) {
        lli i = left;
        lli j = right;
        lli pivot = median(a[i], a[i + (j - i) / 2], a[j]);

        while (1) {
            while (a[i] < pivot) { i++; }
            while (pivot < a[j]) { j--; }
            if (i >= j) { break; }
            swap(a[i], a[j]);
            i++;
            j--;
        }
        quicksort(a, left, i - 1);
        quicksort(a, j + 1, right);
    }

}

int main() {

    lli n;
    cin >> n;

    lli a[n];
    for(auto i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    lli tmp_left = a[0], tmp_right = a[n - 1];

    lli ans = n;

    lli i = 0, j = n - 1;

    bool is_left = false;
    while (1) {
        if (i >= j) { break; }
        i++;
        if(a[i] == tmp_left){
            is_left = true;
        } else {
            tmp_left = a[i];
        }

        while (is_left) {
            j--;
            if (a[j] == tmp_right) {
                ans -= 2;
                is_left = false;
            } else {
                tmp_right = a[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}