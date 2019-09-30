#include <iostream>
#include <vector>

// Fenwick Tree (Binary Indexed Tree)
#ifdef _MSC_VER
#pragma warning(disable:4146)
#endif
template<class T>
class fenwick
{
    std::vector<T> a;
    static size_t msb(size_t v)
    {
        for(size_t i=1; i<sizeof(size_t)*8; i<<=1) v |= v>>i;
        return (v>>1)+1;
    }
public:
    explicit fenwick(size_t N):a(N+1,0){}
    void add(size_t i, T v)
    {
        const size_t N = a.size()-1;
        for(size_t x=i+1; x<=N; x+=x&-x) a[x]+=v;
    }
    T sum(size_t i)
    {
        T t=0;
        for(size_t x=i; x>0; x-=x&-x) t+=a[x];
        return t;
    }
    T sum(size_t i, size_t j){ return sum(j)-sum(i); }
    size_t lower_bound(T v)
    {
        if(v<=0) return 0;
        const size_t N = a.size()-1;
        size_t i=0;
        for(size_t k=msb(N); k>0; k>>=1)
            if (i+k<=N && v>a[i+k])
            {
                v -= a[i+k];
                i += k;
            }
        return i;
    }
};

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    for(int N,M; std::cin >> N >> M; ) {
        std::vector<std::vector<std::pair<int,int>>> lr(M+1);
        for(int i=0; i<N; ++i) {
            int l,r; std::cin >> l >> r;
            lr[r-l+1].emplace_back(l,r);
        }
        auto n=N;
        fenwick<int> m(M+2);
        for(int d=1; d<=M; ++d) {
            for(const auto&v:lr[d]) {
                m.add(v.first,1);
                m.add(v.second+1,-1);
                --n;
            }
            int c=n;
            for(auto i=d; i<=M; i+=d) c+=m.sum(i+1);
            std::cout << c << "\n";
        }
    }
}