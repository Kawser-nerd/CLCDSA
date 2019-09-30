//#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include <iomanip>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PLDLD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VB;
 
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()
 
const LD eps=1e-10;
const long long INFLL=(LL)(1e9)*(LL)(1e9);
const int INF=1e9;
 
template<class T>
void chmin(T& a, const T b)
{
	if(a>b)
		a=b;
}
template<class T>
void chmax(T& a, const T b)
{
	if(a<b)
		a=b;
}
 
const LL pow(const LL p, const LL q)
{
	LL t=1;
	for(int i=0;i<q;i++)
		t*=p;
	return t;
}

template <typename T>
struct has_iter
{
	private:
		template <typename U>
		static constexpr true_type check(typename U::iterator*);
		template <typename U>
		static constexpr false_type check(...);

	public:
		static constexpr bool value = decltype(check<T>(nullptr))::value;
};


template<typename T, typename U = typename T::iterator>
void print(const T& container)
{
		auto&& first=begin(container), last=end(container);
		auto&& back=prev(last);
		for(auto e=first; e!=last; e=next(e))
			cout<<*e<<" \n"[e==back];
}


extern void* enabler;
template<typename Head, typename enable_if<!has_iter<Head>::value>::type*& = enabler>
void print(const Head& head)
{
	cout<<head<<endl;
}

template<> void print<string>(const string& container)
{
	cout<<container<<endl;
}

template<typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	cout<<head<<" ";
	print(tail...);
}

void io_speedup()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec)
{
	for(T& x: vec) is >> x;
	return is;
}


template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p)
{
	os<<'('<<p.first<<", "<<p.second<<')';
	return os;
}

template<typename T>
vector<T> read(int n)
{
	vector<T> t(n);
	cin>>t;
	return t;
}

template<typename T>
T read()
{
	T t;
	cin>>t;
	return t;
}


template<unsigned int N> struct IsPrime {
	static const int size=(N>>5) + 1;
	unsigned int is_prime[size];
	constexpr IsPrime() : is_prime() {
		is_prime[0]=0x3;
		for(unsigned int i=2;i<N;i++)
		{
			if((is_prime[i>>5] & (1u<<(i&0x1f))) > 0)  continue;
			for(int j=i+i;j<N;j+=i)
				is_prime[j>>5]|=(1u<<(j&0x1f));
		}
	}
	constexpr bool operator[] (const int p) const
	{
		return (is_prime[p>>5] & (1u<<(p&0x1f))) == 0;
	}
};

template<int N> struct LikelyPrime {
	unsigned short sum[N+1];
	constexpr LikelyPrime(const IsPrime<N> pr) : sum() {
		for(int i=3;i<N;i++)
			sum[i+1]=sum[i]+(unsigned short)((pr[i] && pr[(i+1)/2])?1:0 );
	}
};

int main()
{
	io_speedup();
	constexpr IsPrime<100001> pr;
	constexpr LikelyPrime<100001> s(pr);
	int q;cin>>q;
	REP(i,q)
	{
		int l,r;
		cin>>l>>r;
		cout<<s.sum[r+1]-s.sum[l]<<endl;
		//print(s.sum[r+1]-s.sum[l]);
	}
} ./Main.cpp:52:30: warning: inline function 'has_iter<std::__1::basic_string<char> >::check<std::__1::basic_string<char> >' is not defined [-Wundefined-inline]
                static constexpr true_type check(typename U::iterator*);
                                           ^
./Main.cpp:57:42: note: used here
                static constexpr bool value = decltype(check<T>(nullptr))::value;
                                                       ^
1 warning generated.