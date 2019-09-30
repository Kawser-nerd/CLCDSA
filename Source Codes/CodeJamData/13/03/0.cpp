#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<char> > fair;

bool cmp(const vector<char> & a, const vector<char> & b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    for (int i=0; i<a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return true;
}

void fill(int p, int l, vector<char> & result, int rest) {
    if (p*2 + 1 == l) {
        int i=0;
        while(i*i <= rest) {
            result[p] = i;
            fill(p+1, l, result, rest - i*i);
            ++i;
        }
    } else if (p*2 + 1 > l) {
        fair.push_back(vector<char>());
        for (int i=0; i<result.size(); ++i) {
            fair.back().push_back(result[i]);
        }
        if ((l & 1) == 0) {
            fair.back().push_back(result.back());
        }
        for (int i=result.size()-2; i>=0; --i) {
            fair.back().push_back(result[i]);
        }
    } else {
        int i=0;
        if (p==0) ++i;
        while (i*i*2 <= rest) {
            result[p] = i;
            fill(p+1, l, result, rest - i*i*2);
            ++i;
        }
    }
}

vector<char> square(vector<char> a) {
    vector<char> result(a.size() * 2, 0);
    for (int i=0; i<a.size(); ++i) {
        for (int j=0; j<a.size(); ++j) {
            result[i+j] += a[i] * a[j];
        }
    }
    while ((result.size() > 1) && (result.back() == 0)) {
        result.pop_back();
    }
    return result;
}

int find(vector<char> num) {
    int A = 0, B = fair.size(), C;
    while (B-A > 1) {
        C = (A+B)/2;
        if (cmp(fair[C], num)) {
            A = C;
        } else {
            B = C;
        }
    }
    return A;
}

void print(vector<char> a) {
    for (int i=0; i<a.size(); ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
}

char A[200], B[200];
int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);
    scanf(" %s %s", A, B);
    vector<char> AA, BB;
    for (int i=0; A[i] != NULL; ++i) {
        AA.push_back(A[i]-'0');
    }
    
    int i=AA.size() - 1;
    while(AA[i] == 0) {
        AA[i] = 9;
        --i;
    }
    --AA[i];
    
    for (int i=0; B[i] != NULL; ++i) {
        BB.push_back(B[i]-'0');
    }

    int a_pos = find(AA);
    int b_pos = find(BB);
/*
    print(AA);
    print(fair[a_pos]);
    print(BB);
    print(fair[b_pos]);
*/
    printf("%d\n", b_pos - a_pos);
}

void preprocessing() {

    vector<char> digit(1);
    digit[0] = 0;
    fair.push_back(digit);
    digit[0] = 1;
    fair.push_back(digit);
    digit[0] = 2;
    fair.push_back(digit);
    digit[0] = 3;
    fair.push_back(digit);

    for (int i=2; i<52; ++i) {
        vector<char> result((i+1)/2);
        fill(0, i, result, 9);
    }
/*
    digit.resize(9);
    digit[0] = 4;
    for (int i=1; i<9; ++i) {
        digit[i] = 0;
    }
    
    int k = 0;
    while(cmp(fair[k], digit)) {
        for (int i=0; i<fair[k].size(); ++i) {
            printf("%d", fair[k][i]);
        }
        printf("\n");
        ++k;
    }
*/
//    printf("%d\n", (int)fair.size());


    for (int i=0; i<fair.size(); ++i) {
        fair[i] = square(fair[i]);
    }
}

int main() {
    preprocessing();
    int t; scanf("%d", &t);
    while(t--) {
        make();
    }
    return 0;
}
