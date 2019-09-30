#include <bits/stdc++.h>

using namespace std;

/*
 * R+Y=O
 * B+Y=G
 * R+B=V
 */

 // R B Y

string calc2(vector<int> vec) {
    vec[0] -= vec[3];
    vec[2] -= vec[5];
    vec[4] -= vec[1];
    int r = vec[0], y = vec[2], b = vec[4];
    if(r < 0 || y < 0 || b < 0) {
        return "IMPOSSIBLE";
    }
    if(r == 0 && vec[3] > 0) {
        return "IMPOSSIBLE";
    }
    if(y == 0 && vec[5] > 0) {
        return "IMPOSSIBLE";
    }
    if(b == 0 && vec[1] > 0) {
        return "IMPOSSIBLE";
    }
    if(r > b+y) {
        return "IMPOSSIBLE";
    }
    if(b > r+y) {
        return "IMPOSSIBLE";
    }
    if(y > b+r) {
        return "IMPOSSIBLE";
    }
    string s = "";
    if(r > 0) {
        s = "R";
        r--;
    } else if(y > 0) {
        s = "Y";
        y--;
    } else {
        s = "B";
        b--;
    }
    while(r+y+b > 0) {
        if(s[s.size()-1] == 'R') {
            if(y > b) {
                s += "Y";
                y--;
            } else {
                s += "B";
                b--;
            }
        } else if(s[s.size()-1] == 'Y') {
            if(r > b) {
                s += "R";
                r--;
            } else {
                s += "B";
                b--;
            }
        } else {
            if(r > y) {
                s += "R";
                r--;
            } else {
                s += "Y";
                y--;
            }
        }
    }
    if(s[0] == s[s.size()-1]) {
        for(int i=1;i<s.size()-1;i++) {
            if(s[i] != s[0] && s[i+1] != s[0]) {
                s = s.substr(0,i+1) + s.substr(0,1) + s.substr(i+1);
                s.resize(s.size()-1);
                break;
            }
        }
    }
    return s;
}

string calc(vector<int> vec) {
    int sum = 0;
    for(int i=0;i<6;i++) {
        sum += vec[i];
    }
    if(vec[0] == vec[3] && vec[0]+vec[3] == sum) {
        string res = "";
        for(int i=0;i<vec[0];i++) {
            res += "RG";
        }
        return res;
    }
    if(vec[2] == vec[5] && vec[2]+vec[5] == sum) {
        string res = "";
        for(int i=0;i<vec[2];i++) {
            res += "YV";
        }
        return res;
    }
    if(vec[4] == vec[1] && vec[4]+vec[1] == sum) {
        string res = "";
        for(int i=0;i<vec[4];i++) {
            res += "BO";
        }
        return res;
    }
    string res = calc2(vec);
    if(res == "IMPOSSIBLE") {
        return res;
    }
    for(int i=0;i<res.size();i++) {
        if(res[i] == 'R' && vec[3] > 0) {
            vec[3]--;
            res = res.substr(0,i+1) + "G" + res.substr(i);
        } else if(res[i] == 'Y' && vec[5] > 0) {
            vec[5]--;
            res = res.substr(0,i+1) + "V" + res.substr(i);
        } else if (res[i] == 'B' && vec[1] > 0) {
            vec[1]--;
            res = res.substr(0,i+1) + "O" + res.substr(i);
        }
    }
    return res;
}

int main() {
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++) {
        int n;
        cin >> n;
        //(r,o,y,g,b,v)
        vector<int> vec(6);
        for(int i=0;i<6;i++) {
            cin >> vec[i];
        }
        cout << "Case #" << casito << ": " << calc(vec) << endl;
    }
}