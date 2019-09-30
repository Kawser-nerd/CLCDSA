#include<iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    double total = 0;
    string line;
    cin >> n >> line;

    for(int i = 0; i < n; i++){
        switch (line[i]){
            case 'A':
                total += 4;
                break;
            case 'B':
                total += 3;
                break;
            case 'C':
                total += 2;
                break;
            case 'D':
                total += 1;
                break;
            default:
                break;
        }
    }

    double gpa = total / n;

    printf("%.10f\n", gpa);

    return 0;
}