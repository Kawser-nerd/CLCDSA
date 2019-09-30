#include<iostream>
using namespace std;

void addDate(int &y, int &m, int &d);
bool isLeap(int y, int m, int d);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    while(true){
        if(((double)y / m / d) - (y / m / d) > 0){
            addDate(y, m, d);
        }
        else{
            printf("%d/%02d/%02d\n", y, m, d);
            return 0;
        }
    }
}

void addDate(int &y, int &m, int &d){
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        d++;
        if(d > 31){
            d = 1;
            m++;
        }
    }
    else if(m == 4 || m == 6 || m == 9 || m == 11){
        d++;
        if(d > 30){
            d = 1;
            m++;
        }
    }
    else{
        if(isLeap(y, m, d)){
            d++;
            if(d > 29){
                d = 1;
                m++;
            }
        }
        else{
            d++;
            if(d > 28){
                d = 1;
                m++;
            }
        }
    }

    if(m > 12){
        m = 1;
        y++;
    }
}

bool isLeap(int y, int m, int d){
    bool leap;
    if(y % 400 == 0){
        leap = true;
    }
    else if(y % 100 == 0){
        leap = false;
    }
    else if(y % 4 == 0){
        leap = true;
    }
    else{
        leap = false;
    }

    return leap;
}