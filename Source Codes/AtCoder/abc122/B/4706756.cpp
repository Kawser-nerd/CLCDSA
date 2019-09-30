/*
    Converted from Scratch by scratch2cpp (https://github.com/yos1up/scratch2cpp).
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define debug cerr << "--" << __LINE__ << "--" << "\n"
typedef long long ll;
using namespace std;

const double EPS = 1e-8;

class Var{ // NOTE: immutable
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
        //cause side-effect: errno can be ERANGE after calling strtod
        strtod(s.c_str(), &ep);
        //Scratch 3.0 recognize the string cause underflows or overflows as Numeric
        return NULL != ep && '\0' == ep[0] && s[0] != '\0';
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
    /*
    static bool isNearInteger(const double &x){
        return fabs(round(x) - x) < EPS;
        // TODO: allow integer type in Var class
    }
    static bool isNearNumber(const double &x, const double &y){
        return fabs(x - y) < EPS;
    }
    */
    string asString() const{
        if (type == STRING) return sval;
        if (floor(dval) == dval) return to_string((ll)round(dval));
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

class VarList{
public:
    vector<Var> data;
    VarList(const vector<Var> &x) { data = x; }
    void push_back(const Var &x){ data.push_back(x); }
    void pop_back(){ data.pop_back(); }
    void clear(){ data.clear(); }
    int size(){ return (int) data.size(); }
    Var getLineOfList(const Var &index) const{
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        // (unlike 'letterOf', index==0.9 does not work.)
        if (0 <= idx && idx < data.size()) return data[idx];
        return Var();
    }
    void setLineOfListTo(const Var &index, const Var &v){
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        if (0 <= idx && idx < data.size()) data[idx] = v;
    }
    void deleteLineOfList(const Var &index){
        /* index: 1-origined */
        string kwd = index.asString();
        if (kwd == "all"){
            data.clear();
        }else if (kwd == "last"){
            data.pop_back();
        }else{
            int idx = (int)index.asNumber() - 1;
            if (0 <= idx && idx < data.size()) data.erase(data.begin() + idx);
        }
    }
    void insertAtIndexOfList(const Var &item, const Var &index){
        /* index: 1-origined */
        int idx = (int)index.asNumber() - 1;
        if (0 <= idx && idx <= data.size()) data.insert(data.begin() + idx, item);   
    }
    void insertAtRandomOfList(const Var &item){
        int idx = rand() % (data.size() + 1);
        data.insert(data.begin() + idx, item);
    }
    string asString() const{
        /* concatenate elements of list with space */
        // TODO: concatenated without spaces only if all elements are single characters.
        // (Is it an official bug? (or feature?))
        string ret;
        for(int i=0;i<data.size();i++){
            if (i > 0) ret += ' ';
            ret += data[i].asString();
        }
        return ret;        
    }
    int itemNumOfList(const Var &item) const{
        auto itr = find(data.begin(), data.end(), item);
        if (itr == data.end()) return 0;
        return 1 + (int)(itr - data.begin());
        /* index: 1-origined */
    }
    friend ostream& operator << (ostream& os, const VarList& p);
};
ostream& operator << (ostream& os, const VarList& p){
    os << p.asString();
    return os;
}

double randUniform(double x, double y){
    if (x > y) return randUniform(y, x);
    if (floor(x) == x && floor(y) == y){
        ll xi = (ll)round(x), yi = (ll)round(y);
        return xi + rand() % (yi - xi + 1);
    }else{
        return x + (y - x) * (0.0 + rand()) / RAND_MAX;
    }
}

Var buf_answer; // for "answer"

// ============================= Scripts =============================

// variable declaration
Var var_i(4);
Var var_????(3);
Var var_??????(3);

// list declaration

// prototype declaration of functions
int main();

// contents of functions
int main(){
    cin >> buf_answer;
    var_?????? = Var(0);
    var_???? = Var(0);
    var_i = Var(1);
    for (int cnt_0=0;cnt_0<Var(buf_answer.asString().size()).asNumber();cnt_0++){
        if ((Var("ACGT").asString().find(letterOf(var_i, buf_answer).asString()) != string::npos)){
            var_???? += Var(1);
        } else {
            var_???? = Var(0);
        }
        var_i += Var(1);
        if ((var_???? > var_??????)){
            var_?????? = var_????;
        }
    }
    cout << var_?????? << endl;
    return 0;
}