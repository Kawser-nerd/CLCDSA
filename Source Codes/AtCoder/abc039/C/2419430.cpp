#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, pos, octave = "WBWBWWBWBWBW";
    int i,j;
    cin >> s;
    for(i=0; i<20; i++) {
        for(j=0;j<12;j++) {
            if(s[i+j] != octave[j]) break;
            if(j == 11 || i+j==19) {
                switch(i) {
                    case 0: pos="Do"; break;
                    case 1: pos="Si"; break;
                    case 3: pos="La"; break;
                    case 5: pos="So"; break;
                    case 7: pos="Fa"; break;
                    case 8: pos="Mi"; break;
                    case 10: pos="Re"; break;
                    case 12: pos="Do"; break;
                    default: pos="Fault";
                }
                cout << pos << endl;
                return 0;
            }
        }
    }
}