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

class Var{ // NOTE: immutable
public:
    mutable string sval;
    mutable long double dval;
    enum NumericState {UNKNOWN = -1, STRINGY = 0, NUMERIC = 1};
    mutable NumericState numericState;
    mutable bool svalValid, dvalValid; // TODO: initialize at here?

    Var(){
        *this = Var("");
    }
    Var(string s){
        sval = s;
        svalValid = true; dvalValid = false;
        numericState = UNKNOWN;
    }
    Var(long double d){
        dval = d;
        svalValid = false; dvalValid = true;
        numericState = NUMERIC;
    }
    Var(const Var &v){
        sval = string(v.sval); dval = v.dval;
        svalValid = v.svalValid; dvalValid = v.dvalValid;
        numericState = v.numericState;
    }
    void fillDval() const{
        if (dvalValid) return;
        double d;
        bool numeric = isNumericString(sval, &d);
        if (numeric){
            numericState = NUMERIC;
            dval = d;
        }else{
            numericState = STRINGY;
            dval = 0.0;
        }        
        dvalValid = true;
    }
    static bool isNumericString(const string &s, double *ptr) {
        char* ep;
        // cause side-effect: errno can be ERANGE after calling strtod
        *ptr = strtod(s.c_str(), &ep);
        // TODO: support long double (with strtold)
        // Scratch 3.0 recognize the string cause underflows or overflows as Numeric
        return NULL != ep && '\0' == ep[0] && s[0] != '\0';
    }
    bool isNumeric() const{
        fillDval();
        return numericState == NUMERIC;
    }    
    void fillSval() const{
        if (svalValid) return;
        sval = (floor(dval) == dval) ? to_string((ll)dval) : to_string(dval);
        svalValid = true;
    }       
    long double asNumber() const{
        fillDval();
        return dval;
    } 
    string asString() const{
        fillSval();
        return sval;
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
        } // compare as number if both can be interpreted as numeric
        return this->asString() < y.asString();
    }
    bool operator>(const Var &y) const{
        return y < *this;
    }
    bool operator==(const Var &y) const{
        if (this->isNumeric() && y.isNumeric()){
            return this->asNumber() == y.asNumber();
        } // compare as numeric if both are numeric
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

long double randUniform(const long double x, const long double y){
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
Var var_N(8);
Var var_Q(3);
Var var_S("ACACTACG");
Var var_i(4);
Var var_tmp(3);

// list declaration
VarList list_l({Var(3), Var(2), Var(1)});
VarList list_r({Var(7), Var(3), Var(8)});
VarList list_AC({Var(0), Var(1), Var(1), Var(2), Var(2), Var(2), Var(3), Var(3)});

// prototype declaration of functions
int main();
int func_init();
int func_main();

// contents of functions
int main(){
    func_init();
    cin >> buf_answer;
    var_N = buf_answer;
    cin >> buf_answer;
    var_Q = buf_answer;
    cin >> buf_answer;
    var_S = buf_answer;
    for (int cnt_0=0;cnt_0<var_Q.asNumber();cnt_0++){
        cin >> buf_answer;
        list_l.push_back(buf_answer);
        cin >> buf_answer;
        list_r.push_back(buf_answer);
    }
    func_main();
    return 0;
}

int func_init(){
    list_AC.clear();
    list_l.clear();
    list_r.clear();
    return 0;
}

int func_main(){
    var_tmp = Var(0);
    list_AC.push_back(var_tmp);
    var_i = Var(2);
    while (!(var_i > var_N)){
        if ((letterOf((var_i - Var(1)), var_S) == Var("A"))){
            if ((letterOf(var_i, var_S) == Var("C"))){
                var_tmp = (var_tmp + Var(1));
            }
        }
        list_AC.push_back(var_tmp);
        var_i = (var_i + Var(1));
    }
    var_i = Var(1);
    while (!(var_i > var_Q)){
        cout << (list_AC.getLineOfList(list_r.getLineOfList(var_i)) - list_AC.getLineOfList(list_l.getLineOfList(var_i))) << endl;
        var_i = (var_i + Var(1));
    }
    return 0;
}