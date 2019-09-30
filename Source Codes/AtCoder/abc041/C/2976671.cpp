#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

typedef std::pair<int, int> Student;

int main(void) {
    cout << std::fixed << std::setprecision(10);
    std::vector<Student> student;
    int n, m1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m1);
        student.push_back(std::make_pair(m1, i + 1));
    }
    std::sort(student.begin(), student.end(), std::greater<Student>());
    for (int i = 0; i < n; i++) {
        printf("%d\n", student[i].second);
    }

    return 0;
}