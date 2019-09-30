/* converted by scratch2cpp (https://github.com/yos1up/scratch2cpp)
   This script is compatible with the following compilers:
   - GCC (unless every name of variables contains non-ascii characters)
   - Clang 
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define debug cerr << "--" << __LINE__ << "--" << "\n"
using namespace std;

const double EPS = 1e-8;

static int roundToInt(double x){
    return (x < 0) ? -(int)(-x + 0.5) : (int)(x + 0.5);
}


class Var{
public:
    string sval;
    double dval;
    enum VarType {STRING = 0, NUMBER = 1};
    VarType type;
    enum NumericState {UNKNOWN = -1, STRINGY = 0, NUMERIC = 1};
    mutable NumericState numericState;

    Var(){sval = ""; type = STRING; numericState = STRINGY;} // represent null?
    Var(string s){
        sval = s; type = STRING; numericState = UNKNOWN;
    }
    Var(double d){dval = d; type = NUMBER; numericState = NUMERIC;}
    Var(const Var &v){
        sval = string(v.sval); dval = v.dval;
        type = v.type; numericState = v.numericState;
    }
    static bool isNumericString(const string &s) {
        char* ep;
        strtod(s.c_str(), &ep);
        return !ep || !*ep;
        // TODO: In Scratch '000' is regarded as non-numeric (but here regarded as numeric)
    }
    bool isNumeric() const{
        if (type == NUMBER) return true;
        if (numericState != UNKNOWN) return numericState == NUMERIC;
        bool numeric = isNumericString(sval);
        numericState = (numeric) ? NUMERIC : STRINGY;
        return numeric;
    }
    double asNumber() const{
        if (type == NUMBER) return dval;
        return (isNumeric()) ? atof(sval.c_str()) : 0.0;
    }
    static bool isNearInteger(const double &x){
        return fabs(round(x) - x) < EPS;
        // TODO: allow integer type in Var class
    }
    static bool isNearNumber(const double &x, const double &y){
        return fabs(x - y) < EPS;
    }
    string asString() const{
        if (type == STRING) return sval;
        if (isNearInteger(dval)) return to_string(roundToInt(dval));
        return to_string(dval);
    }
    Var operator+(const Var &y) const{
        return Var(this->asNumber() + y.asNumber());
    }
    Var operator+=(const Var &y){
        *this = *this + y;
        return *this;
    }
    Var operator-(const Var &y) const{
        return Var(this->asNumber() - y.asNumber());
    }
    Var operator*(const Var &y) const{
        return Var(this->asNumber() * y.asNumber());
    }
    Var operator/(const Var &y) const{
        return Var(this->asNumber() / y.asNumber());
    }
    Var operator%(const Var &y) const{
        return Var(fmod(this->asNumber(), y.asNumber()));
    }
    bool operator<(const Var &y) const{
        if (this->isNumeric() && y.isNumeric()){
            return this->asNumber() < y.asNumber();
        }// compare as number if both can be interpreted as numeric
        return this->asString() < y.asString();
    }
    bool operator>(const Var &y) const{
        return y < *this;
    }
    bool operator==(const Var &y) const{
        if (this->isNumeric() && y.isNumeric()){
            return this->asNumber() == y.asNumber();
        }// compare as numeric if both are numeric
        return this->asString() == y.asString();
    }
    friend ostream& operator << (ostream& os, const Var& p);
    friend istream& operator >> (istream& is, const Var& p);
};
ostream& operator << (ostream& os, const Var& p){
    os << p.asString();
    return os;
}
istream& operator >> (istream& is, Var& p){
    string s; is >> s; p = Var(s);
    return is;
}

Var letterOf(Var index, Var sourceString){
    /* index: 1-origined */
    string str = sourceString.asString();
    int idx = (int)(index.asNumber() - 1);
    // seem to be dirty but Scratch seems to do like this.
    // ex. letterOf(0.01, "world") == "w", letterOf(1.99, "world") == "w", letterOf(5.99, "world") == "d"
    if (0 <= idx && idx < str.size()) return Var(str.substr(idx, 1));
    return Var();
}

// TODO: should we make a new class for vector<Var>?
Var getLineOfList(const Var &index, const vector<Var> &list){
    /* index: 1-origined */
    int idx = (int)index.asNumber() - 1;
    // (unlike 'letterOf', index==0.9 does not work.)
    if (0 <= idx && idx < list.size()) return list[idx];
    return Var();
}
void setLineOfListTo(const Var &index, vector<Var> &list, const Var &v){
    /* index: 1-origined */
    int idx = (int)index.asNumber() - 1;
    if (0 <= idx && idx < list.size()) list[idx] = v;
}
void deleteLineOfList(const Var &index, vector<Var> &list){
    /* index: 1-origined */
    int idx = (int)index.asNumber() - 1;
    if (0 <= idx && idx < list.size()) list.erase(list.begin() + idx);
}
void insertAtIndexOfList(const Var &item, const Var &index, vector<Var> &list){
    /* index: 1-origined */
    int idx = (int)index.asNumber() - 1;
    if (0 <= idx && idx <= list.size()) list.insert(list.begin() + idx, item);   
}
void insertAtRandomOfList(const Var &item, vector<Var> &list){
    int idx = rand() % (list.size() + 1);
    list.insert(list.begin() + idx, item);
}
Var contentsOfList(const vector<Var> &list){
    /* concatenate elements of list with space */
    string ret;
    for(int i=0;i<list.size();i++){
        if (i > 0) ret += ' ';
        ret += list[i].asString();
    }
    return Var(ret);
}

double randUniform(double x, double y){
    if (x > y) return randUniform(y, x);
    if (Var::isNearInteger(x) && Var::isNearInteger(y)){
        int xi = roundToInt(x), yi = roundToInt(y);
        return xi + rand() % (yi - xi + 1);
    }else{
        return x + (y - x) * (0.0 + rand()) / RAND_MAX;
    }
}

Var buf_answer; // for "answer"

// ============================= Scripts =============================
Var var_a(0);
Var var_b(0);
Var var_c(0);

// prototype declaration
int main();

int main(){
    cin >> buf_answer;
    var_a = buf_answer;
    cin >> buf_answer;
    var_b = buf_answer;
    cin >> buf_answer;
    var_c = buf_answer;
    if (((var_c<(var_a+var_b)) || (var_c == (var_a+var_b)))){
        cout << Var("Yes") << "\n";
    }else{
        cout << Var("No") << "\n";
    }
    return 0;
}