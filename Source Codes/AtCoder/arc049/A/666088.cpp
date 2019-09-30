//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <array>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
template < typename T >
constexpr T inf() { return numeric_limits<T>::max();}
template < typename T >
constexpr T pi(){ return static_cast<T>(acos(T{})) ; };
#define loop(a) for(size_t i{};i<a;++i)
#define rep(i,n) for(size_t i{};i<n;++i)
#define step(i,f,l,s) for(size_t i{f};i<=l;i+=s)
#define puts(s) (cout << s << endl)
#define all(v) v.begin(), v.end()

int main()
{
    string s;
    cin >> s;
    size_t n{};
    array<size_t,4> v;
    for(auto&& e : v)
        cin >> e;
    loop(s.size()){
        if(i==v[n]){
            cout << '"' ;
            ++n;
        }
        cout << s[i] ;
    }
    if(v[3]==s.size())
        cout << '"';
    cout << endl;
}