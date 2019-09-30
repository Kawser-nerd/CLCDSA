#include <iterator>
#include <array>
#include <map>
#include <functional>
#include <cstdio>
#include <vector>
template<typename T>
class LazyPtr
{
    public:
        template<typename... Args> T& operator()(Args... args) { if(!init)new (_buf)T(args...); init = true; return **this;}
        T* operator->() { return ((T*)_buf); }
        T& operator*() { return *((T*)_buf); }

    private:
        bool init = false;
        char _buf[sizeof(T)];
};



namespace XX
{   
    template<template<typename> class Compare, typename T>
    inline T& UP(T& x, const T& y){if(Compare<T>()(y, x)) x = y; return x;}
    template<typename Compare, typename T>
    inline T& UP(T& x, const T& y, Compare comp){if(comp(y, x)) x = y; return x;}

    template<typename T> inline T& GT(T& x, const T& y){return UP<std::greater>(x, y);}
    template<typename T> inline T& LS(T& x, const T& y){return UP<std::less>(x, y);}

    template<typename T>
    struct Mapper
    {
        int operator[](const T& v) { int& ret = table[v]; if(!ret) rtable[ret = table.size()] = v; return ret - 1; }
        template<typename... Args> int operator()(Args... args) { return (*this)[T(args...)]; }
        T rev(int idx){return rtable[idx + 1];}
        std::map<T, int> table;
        std::map<int, T> rtable;
    };

    template<typename T, int S>
    struct ReferenceArray
    {
        struct It {typename std::array<T*, S>::iterator it; T& operator*(){return **it;} void operator++(){it++;} bool operator!=(const It& other){return it != other.it;} };
        int size()const{return _ptr.size();}
        It begin()const{return {_ptr.begin()};}
        It end()const{return {_ptr.end()};}
        T& operator[](int idx)const{return *_ptr[idx];}
        mutable std::array<T*, S> _ptr;
    };
    template<typename T, typename... Args> 
    ReferenceArray<T, sizeof...(Args) + 1> MAKEV(T& arg1, Args&... args) {return {&arg1, &args...};}

    struct Range
    {   
        struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
        Range(int ee):b(0),e(ee){}
        Range(int bb, int ee):b(bb), e(ee){}
        It begin(){return {b, (b < e? 1: -1)};}
        It end(){return {e, 0};}
        int b, e;
    };

}



template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(char*,"%s")DEF(unsigned int, "%u")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
template<> int RD<char*>(char*& arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), std::printf(ScanfSpecifier<Args>::value, args), 0)...}; }
template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}




#include <algorithm>
#include <vector>
namespace XX
{
    template<typename... Datas>
    class UnionFind
    {
        public:
            struct Node:public Datas...
            {
                int _parent = -1;
                int size(){return -_parent;}
                void operator+=(Node& other) { int dummy[] = {(Datas::operator+=(other), 0)...}; }
            };
            UnionFind(int size) :_data(size) {}

            Node& operator[](int idx)
            {
                return _data[(*this)(idx)];
            }

            int operator()(int n)
            {
                if(_data[n]._parent < 0)
                    return n;
                else
                {
                    int ret = (*this)(_data[n]._parent);
                    if(ret != _data[n]._parent)
                        _backup.push_back({n, _data[n]});

                    return _data[n]._parent = (*this)(_data[n]._parent);
                }
            }

            bool operator()(int a, int b)
            {
                int pa = (*this)(a), pb = (*this)(b);
                if(pa == pb)
                    return false;
                else
                {
                    _backup.push_back({pa, _data[pa]});
                    _backup.push_back({pb, _data[pb]});

                    if(_data[pa]._parent == _data[pb]._parent)
                        _data[pa]._parent--;
                    else if(_data[pa]._parent > _data[pb]._parent)
                        std::swap(pa, pb);

                    _data[pa] += _data[pb];
                    _data[pb]._parent = pa;
                    return true;
                }
            }

            void push()
            {
                _stk.push_back(_backup.size());
            }
            void pop()
            {
                int b = _stk.back();
                _stk.pop_back();

                for(int i = _backup.size() - 1; i >= b; i--)
                {
                    _data[_backup[i].first] = _backup[i].second;
                }
                _backup.resize(b);
            }

        private:
            std::vector<std::pair<int, Node>> _backup;
            std::vector<int> _stk;
            std::vector<Node> _data;
    };
}


//alias
//for union/find
template<typename... Datas>
using UF = XX::UnionFind<Datas...>; 
template<typename T> T& UMAX(T& x, T y){return XX::UP<std::greater>(x, y);}
template<typename T> T& UMIN(T& x, T y){return XX::UP<std::less>(x, y);}
using XX::UP; //(x,y) comp
using RG = XX::Range;
using XX::MAKEV;
using XX::Mapper;
//RD[L],RDV[L],WT[L],WTV[L] for i/o
//template
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

const int SIZE = 100009;
int ans[SIZE];
int A[SIZE], B[SIZE];
struct Q
{
    int idx;
    int x, y, z;
}qs[SIZE];
struct Data
{
    int amt = 1;
    void operator+=(Data& other)
    {
        amt += other.amt;
    }
};

LazyPtr<UF<Data>> puf;
void f(int l, int r, int ql, int qr)
{
    //WTL('?',l, r, ql, qr);
    if(ql >= qr || l >= r)
        return;

    auto& uf = *puf;
    int m = (l + r) >> 1;
    uf.push();
    for(int j = l; j <= m; j++)
    {
        uf(A[j], B[j]);
    }

    int qm = ql;
    for(int i = ql; i < qr; i++)
    {
        int tmp;
        if(uf(qs[i].x) == uf(qs[i].y))
            tmp = uf[qs[i].x].amt;
        else
            tmp = uf[qs[i].x].amt + uf[qs[i].y].amt;

//        WTL('#', qs[i].idx, qs[i].x, qs[i].y, qs[i].z, tmp);
        
        if(tmp >= qs[i].z)
        {
            if(!ans[qs[i].idx] || ans[qs[i].idx] > m + 1)
                ans[qs[i].idx] = m + 1;
            swap(qs[qm++], qs[i]);
        }
    }

    f(m + 1, r, qm, qr);
    
    uf.pop();

    f(l, m, ql, qm);
}
int main()
{
    int N, M;
    RD(N, M);

    for(int i = 0; i < M; i++)
    {
        RD(A[i], B[i]);
        A[i]--;
        B[i]--;
    }
    puf(N);

    int Q;
    RD(Q);
    for(int i = 0; i < Q; i++)
    {
        qs[i].idx = i;
        RD(qs[i].x, qs[i].y, qs[i].z);
        qs[i].x--;
        qs[i].y--;
    }

    f(0, M, 0, Q);
    for(int i = 0; i < Q; i++)
        WTL(ans[i]);

}