#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

const char* const REV_MAPPING = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
    int nCases;
    string line;
    scanf("%d", &nCases);
    getline(cin, line);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        getline(cin, line);
        printf("Case #%i: ", iCase);
        for (int i = 0; i < (int) line.size(); i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                printf("%c", REV_MAPPING[(unsigned char) (line[i] - 'a')]);
            } else {
                printf("%c", line[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
