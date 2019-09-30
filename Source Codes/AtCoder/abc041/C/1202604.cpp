#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> student;

bool g(const student& a, const student& b) {
    return a.second > b.second;
}

template <typename List>
void split(const string& s, const string& del, List& res) {
    res.clear();
    string::size_type pos = 0;
    int i = 1;

    while(pos != string::npos) {
        string::size_type p = s.find(del, pos);
        if(p == string::npos) {
            //res.first.push_back(s.substr(pos));
            res.push_back(pair<int, int>(i, stoi(s.substr(pos))));
            break;
        } else {
            // res.push_back(s.substr(pos, p - pos));
            res.push_back(pair<int, int>(i, stoi(s.substr(pos, p-pos))));
        }

        pos = p + del.size();
        i++;
    }
}

int main() {
    vector<pair<int, int>> v_student;
    string line;
    int n;

    cin >> n; cin.ignore();
    getline(cin, line);
    split(line, " ", v_student);
    sort(begin(v_student), end(v_student), g);
    for (auto s: v_student) {
        cout << s.first << endl;
    }
    // sort(v.begin, v.end) =>
    // C++11??sort(begin(v), end(v), algo);
}