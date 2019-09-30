#include <iostream>
#include <string>

using namespace std;

char h[] = {'M','A','R','C','H'};
int n,s[5] = {0};

int main(void) {
    cin >> n;
    string buf;
    for(int i = 0;i < n;i++) {
        cin >> buf;
        for(int ii = 0;ii < 5;ii++) {
            if(buf[0] == h[ii])
                s[ii]++;
        }
    }
    unsigned long long int count = 0;
    for(int a = 0;a < 3;a++) {
        for(int b = a + 1;b < 4;b++) {
            for(int c = b + 1;c < 5;c++) {
                count =  count + (s[a] * s[b] * s[c]);
            }
        }
    }
    cout << count << endl;
}