// apt-get install libgomp1 libboost.* libcgal.* libgmp3.* libgmpxx.* octave3.0.* gnuplot octplot octaviz kayali glibc-doc manpages manpages-dev libglib2.0-dev libglib2.0-doc liblpsolve55-dev lp-solve lp-solve-doc valgrind

#ifndef DBG
#define DBG(x) x
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include <bitset>
#include <iostream>
#include <list>
#include <map>

#define queue stl_queue
#include <queue>
#undef queue
#include <boost/pending/queue.hpp>
namespace std
{
	using ::boost::queue;
}

#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <fstream>
#include <functional>
#include <ext/functional>

#include <tr1/unordered_set>
#include <tr1/unordered_map>

#include <boost/foreach.hpp>
#include <boost/rational.hpp>
#include <boost/pending/disjoint_sets.hpp>
#include <boost/pending/mutable_queue.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/pending/integer_range.hpp>

// BGL
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/reverse_graph.hpp>

#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>

//#include <boost/graph/dijkstra_shortest_paths.hpp>
//#include <boost/graph/floyd_warshall_shortest.hpp>
//#include <boost/graph/johnson_all_pairs_shortest.hpp>
//#include <boost/graph/dag_shortest_paths.hpp>

//#include <boost/graph/kruskal_min_spanning_tree.hpp>
//#include <boost/graph/strong_components.hpp>
//#include <boost/graph/topological_sort.hpp>
//#include <boost/graph/astar_search.hpp>
//#include <boost/graph/max_cardinality_matching.hpp>

/*
#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/ch_graham_andrew.h>

using namespace CGAL;

//typedef   Cartesian<Gmpq>::Point_2        Point_2;
//typedef   Cartesian<T>::Point_2        Point_2;
//typedef   Cartesian<long long>::Point_2        Point_2;
//typedef   Cartesian<int>::Point_2        Point_2;
//typedef   Homogeneous<int>::Point_2        Point_2;
//typedef   Exact_predicates_inexact_constructions_kernel<T>::Point_2        Point_2;

*/

//#include <gmpxx.h>
// mpz_class, mpq_class, mpf_class

//#include <glib-2.0/glib/gchecksum.h>



using namespace std;
using namespace std::tr1;
using namespace __gnu_cxx;
using namespace boost;
#define DBL_ERR 1E-9

typedef long long s64;
typedef unsigned long long u64;

#define foreach_iter(i, c) for(typeof((c)op.begin()) i = (c).begin(); i != (c).end(); ++i)
#define foreach(r,c) BOOST_FOREACH(typeof((c).front())& r, c)
#define auto(n, v) typeof(v) n = (v)






  template <class _Tp>
    struct minimum : public binary_function<_Tp, _Tp, _Tp>
    {
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return min(__x, __y); }
    };

  template <class _Tp>
    struct maximum : public binary_function<_Tp, _Tp, _Tp>
    {
      _Tp
      operator()(const _Tp& __x, const _Tp& __y) const
      { return max(__x, __y); }
    };


// sum_a<=k<b v[k]
template<typename T = int, typename TT = std::vector<T>, typename Top = std::plus<T> >
struct fenwick
{
	TT tree;
	Top op;
	T init;

	inline fenwick(int n = 0, const Top& op = Top(), const T& init = T())
	: tree(n), op(op), init(init)
	{}

	inline void resize(size_t s)
	{
		tree.resize(s);
	}

	inline T query(int b) const
	{
		T sum = init;
		for (; b > 0; b = (b & (b - 1)))
			sum = op(sum, tree[b - 1]);
		return sum; 
	}

	// v[k] += z

	inline void update(int k, int z)
	{
		for (; k < (int)tree.size(); k |= k + 1)
			tree[k] = op(tree[k], z);
	}
};

template<typename T = int, typename TT = std::vector<T>, typename Top = std::plus<T>, typename Tinv = std::negate<T> >
struct ifenwick : public fenwick<T, TT, Top>
{
	typedef fenwick<T, TT, Top> super;
	Tinv inv;

	inline ifenwick(int n = 0, const Top& op = Top(), const T& init = T(), const Tinv& inv = Tinv())
		: super(n, op, init), inv(inv)
	{

	}

	inline T query(int a, int b) const
	{
		return op(super::query(b), inv(super::query(a)));
	};	

        inline T operator[](int k) const
        {
                return query(k, k + 1);
        }

        inline void set(int k, T z)
        {
		update(k, op(inv((*this)[k]), z));
        }
};

template<typename T = unsigned, typename TT = std::vector<T>, typename Top = maximum<T> >
struct dfenwick
{
	TT tree;
	Top op;
	T init;

	inline dfenwick(int n = 0, const Top& op = Top(), const T& init = T())
	: tree(2 * n - 1), op(op), init(init)
	{}

	inline void resize(size_t s)
	{
		tree.resize(2 * s - 1);
	}


	inline T query(int a, int b) const
	{
		T sum = init;
		T nb;
		for (; b && ((nb = (b & (b - 1))) >= a); b = nb)
			sum = op(sum, tree[2 * (b - 1)]);
	
		T na;
		for (; a < b && ((na = ((a - 1) | a) + 1) <= b); a = na)
			sum = op(sum, tree[2 * a - 1]);

		return sum; 
	}

	inline T query(int b) const
	{
		return query(0, b);
	}

	inline T operator[](int k) const
	{
		return tree[2 * k - (k & 1)];
	}

	inline void update(int k, T z)
	{
		for (int j = k; (2 * j) < (int)tree.size(); j |= j + 1)
			tree[2 * j] = op(z, tree[2 * j]);

		for (int j = k; j; j = j & (j - 1))
			tree[2 * j - 1] = op(z, tree[2 * j - 1]);
	}

        inline void set(int k, T z)
        {
                for (int j = k; (2 * j) < (int)tree.size(); j |= j + 1)
		{
			int b = j + 1;
			int a = b & (b - 1);
                        tree[2 * j] = op(op(query(a, k), z), query(k + 1, b));
		}

                for (int j = k; j; j = j & (j - 1))
		{
			int a = j;
			int b = ((a - 1) | a) + 1;
                        tree[2 * j - 1] = op(op(query(a, k), z), query(k + 1, b));
		}
        }
};


template<typename T>
static inline T xgcd(T a, T b, T* px = 0, T* py = 0)
{
	T xp = 1;
	T yp = 0;
	T x = 0;
	T y = 1;
	T t;
	T q;

	while(b != 0)
	{
		t = b;
		q = a / b;
		b = a % b;
		a = t;
		
		t = x;
		x = xp - q*x;
		xp = t;

		t = y;
		y = yp - q*x;
		yp = t;
	}

	if(px)
		*px = xp;
	if(py)
		*py = yp;
	
	return a;
}

// disjoint_sets_with_storage

template<typename T>
struct integer_comp_traits
{
	typedef T t;
};

template<>
struct integer_comp_traits<int>
{
	typedef long long t;
};

template<>
struct integer_comp_traits<unsigned>
{
	typedef unsigned long long t;
};

template<>
struct integer_comp_traits<short>
{
	typedef int t;
};

template<>
struct integer_comp_traits<unsigned short>
{
	typedef unsigned int t;
};

template<>
struct integer_comp_traits<char>
{
	typedef int t;
};

template<>
struct integer_comp_traits<unsigned char>
{
	typedef unsigned int t;
};

/*
template<typename Ta, typename Tm>
static inline Tm tomod(Ta a, Tm m)
{
	if((Ta)(Tm)a == a)
		return (Tm)a;
	else
		return (Tm)(a % (Ta)m);
}

template<>
template<typename T>
static inline T tomod(T a, T m)
{
	return a;
}
*/

template<typename Ta, typename Tm>
static inline Tm modp(Ta a, Tm m)
{
	if((Ta)(Tm)a == a)
		return (Tm)a % (Tm)m;
	else
		return (Tm)((Ta)a %  (Ta)m);
}

template<typename Ta, typename Tm>
static inline Tm mod(Ta a, Tm m)
{
	if(a >= (Ta)0)
		return modp(a, m);
	else
		return m - (Tm)1 - modp(-a - (Ta)1, m);
}

template<typename Ta, typename Tm>
static inline Tm tomod(Ta a, Tm m)
{
	return mod(a, m);
}

template<typename T>
static inline T modrinv(T a, T m)
{
	T x;
	T d = xgcd(a, m, &x, (T*)0); // ax + my = d
	if(d != (T)1)
		return (T)0;
	return mod(x, m);
}

template<typename T>
static inline T modrmul(T a, T b, T m)
{
	typedef typename integer_comp_traits<T>::t Tc;
	return (T)(((Tc)a * (Tc)b) % (Tc)m);
}

template<typename T>
static inline T modradd(T a, T b, T m)
{
	T v = a + b;
	if(v >= m)
		v -= m;
	return v;
}

template<typename T>
static inline T modrsub(T a, T b, T m)
{
	if(a >= b)
		return a - b;
	else
		return (m + a) - b;
}

template<typename T>
static inline T modrneg(T a, T m)
{
	if(!a)
		return 0;
	else
		return m - a;
}

template<typename Ta, typename Tm>
static inline Tm modzinv(Ta a, Tm m)
{
	return modrinv(mod(a, m), m);
}

template<typename Ta, typename Tb, typename Tm>
static inline Tm modzmul(Ta a, Tb b, Tm m)
{
	return modrmul(tomod(a, m), tomod(b, m));
}

template<typename Ta, typename Tb, typename Tm>
static inline Tm modzadd(Ta a, Tb b, Tm m)
{
	return modradd(mod(a, m), mod(b, m));
}

template<typename Ta, typename Tb, typename Tm>
static inline Tm modzsub(Ta a, Tb b, Tm m)
{
	return mod(tomod(a, m) - tomod(b, m), m);
}

template<typename Ta, typename Tm>
static inline Tm modzneg(Ta a, Tm m)
{
	return m - 1 - mod(a - 1, m);
}

template<typename Tb, typename Tm>
static inline Tm modrpow(Tm ap, Tb b, Tm m)
{
	typedef typename integer_comp_traits<Tm>::t T;
	T r = (T)1;
	T a;
	
	if(b < 0)
	{
		a = modrinv(ap, m);
		b = -b;
	}
	else
		a = (T)ap;

	while(b)
	{
		if(b & 1)
		{
			r *= a;
			r %= m;
			--b;
		}
		else
		{
			a *= a;
			a %= m;
			b >>= 1;
		}
	}
	return (Tm)r;
}

template<typename Ta, typename Tb, typename Tm>
static inline Tm modzpow(Ta ap, Tb b, Tm m)
{
	return modrpow(mod(ap, m), b, m);
}


template<typename Ta, typename Tm>
static inline bool lessthanu(Ta a, Tm m)
{
	if(a < 0)
		return true;
		
	if((Ta)(Tm)a != a)
		return false;
	
	return (Tm)a < m;
}

template<typename Ta, typename Tm>
static inline bool lethanu(Ta a, Tm m)
{
	if(a < 0)
		return true;
		
	if((Ta)(Tm)a != a)
		return false;
	
	return (Tm)a <= m;
}

template<typename Tm>
static inline Tm modrfact(Tm a, Tm m)
{
	typedef typename integer_comp_traits<Tm>::t T;
	T r = 1;
	for(Tm i = 1; i < a; ++i)
	{
		r *= (T)i;
		r %= m;
	}
	
	return r;
}

template<typename Ta, typename Tm>
static inline Tm modzfact(Ta a, Tm m)
{
	if(!lessthanu(a, m))
		return (Tm)0;
	
	return modrfact(a, m);
}

template<typename Ta, typename Tm>
static inline Ta modrinc(Ta a, Tm m)
{
	++a;
	if((Tm)a == m)
		a = (Ta)0;

	return a;
}

template<typename Ta, typename Tm>
static inline Tm modrdec(Ta ap, Tm m)
{
	Tm a = (Tm)ap;
	if(a == (Tm)0)
		a = m;
	--a;
	
	return a;
}

struct primes_t
{
	vector<bool> v;

	primes_t(int n = 0)
	{
		resize(n);
	}
	
	void resize(size_t n)
	{
		size_t m = (n + 1) >> 1;
		size_t os = v.size();
		
		if(m <= os)
			return;

		v.resize(m);
		
		if(m > os)
		{
			v[0] = true;
			for(size_t i = 1; i < m; ++i)
			{
				if(v[i])
					continue;

				size_t p = 2 * i + 1;

				size_t j = (p * p) >> 1;
				if(j >= m)
					break;

				if(j < os)
					j = os - ((os - j) % p);
				
				do
				{
					v[j] = true;
					j += p;
				}
				while(j < m);
			}
		}
	}
	
	size_t size()
	{
		return v.size() << 1;
	}

	bool operator[](int p)
	{
		if(p & 1)
		{
			size_t k = p >> 1;
			assert(k < v.size());
			return !v[k];
		}
		else
			return p == 2;
	}
};

template<typename T>
int powm1(T v)
{
	int u = v & 1;
	return 1 - (u + u);
}

template<typename T = unsigned long long, typename Tcanon = identity<T> >
struct binomials_t
{
	vector<T> v;
	Tcanon canon;
	int nextn;
	int nextk;

	binomials_t(Tcanon canon = Tcanon())
	: canon(canon), nextn(0), nextk(0)
	{}
	
	binomials_t(int n, Tcanon canon = Tcanon())
	: canon(canon), nextn(0), nextk(0)
	{
		v.resize(n);
	}

	int idx(int n, int k)
	{
		return (((n + 2) * n + (n & 1)) >> 2) + k;
	}
	
	void resize(int s)
	{
		int i = v.size();
		v.resize(s);
		
		int& n = nextn;
		int& k = nextk;
		
		for(; i < s; ++i)
		{
			if(k == 0)
			{
				v[i] = (T)1;
				if(n < 2)
					++n;
				else
					k = 1;
			}
			else
			{
				int ui = i - ((n + 1) >> 1);

				if(k + k == n)
				{
					v[i] = canon(v[ui - 1] + v[ui - 1]);
					++n;
					k = 0;
				}
				else
				{
					v[i] = canon(v[ui - 1] + v[ui]);
					if((k + k + 1) == n)
					{
						++n;
						k = 0;
					}
					else
						++k;
				}
			}
		}
	}
	
	T operator()(int n, int k)
	{
		k = min(k, n - k);
		int p = idx(n, k);
		if(p < v.size())
			return v[p];
		else
			resize(max(p + 1, v.size() * 2));
	}
};

template<typename T, typename U>
static inline bool miller_rabin(U a, T n)
{
	int s = 0;
	T d = n - 1;
	while(!(d & 1)) {
		d >>= 1;
		++s;
	}

	T ad = modrpow((T)a, d, n);
	if (ad == 1)
		return true;

	for(int i = 0; i < s - 1; ++i)
	{
	        if(ad == n - 1)
			return true;

        	ad = modrmul(ad, ad, n);
	}

	if(ad == n - 1)
		return true;
	return false;
}

primes_t primes(65536);

static inline bool is_prime(unsigned char n)
{
	return primes[n];
}

static inline bool is_prime(char n)
{
	return is_prime((unsigned char)(n >= 0 ? n : -n));
}

// n < 9080191
static inline bool is_prime_small(unsigned n)
{
	if(!(n & 1) && n != 2)
		return false;

	if(n < primes.size())
		return primes[n];

	if(n < 2047)
		return miller_rabin(2, n);

	return miller_rabin(31, n) && miller_rabin(73, n);
}

static inline bool is_prime(unsigned short n)
{
	return is_prime_small((unsigned)n);
}

static inline bool is_prime(short n)
{
	return is_prime((unsigned short)(n >= 0 ? n : -n));
}

static inline bool is_prime(unsigned n)
{
	if(!(n & 1) && n != 2)
		return false;

	if(n < 9080191)
		return is_prime_small(n);
		
	if(n < primes.size())
		return primes[n];

	return miller_rabin(2, n) && miller_rabin(3, n) && miller_rabin(61, n);
}

static inline bool is_prime(int n)
{
	return is_prime((unsigned)(n >= 0 ? n : -n));
}

// n < 10^16
static inline bool is_prime(unsigned long long n)
{
	if(n <= 0xffffffffULL)
		return is_prime((unsigned)n);

	return miller_rabin(2, n) && miller_rabin(3, n) && miller_rabin(7, n) && miller_rabin(61, n) && miller_rabin(24251, n) && n != 46856248255981ULL;	
}

static inline bool is_prime(long long n)
{
	return is_prime((unsigned long long)(n >= 0 ? n : -n));
}

// n < 2^64 probably
static inline bool is_prime_expensive(unsigned long long n)
{
	if(!is_prime(n))
		return false;

	if(n <= 10000000000000000ULL)
		return true;

	if(!miller_rabin(5, n))
		return false;

	for(int i = 11; i < 4096; ++i)
	{
		if(primes[i] && !miller_rabin(i, n))
			return false;
	}

	return true;
}

template<typename T, typename Tp, typename Te>
T factor(T v, vector<pair<Tp, Te> >& r, T limit = (T)0)
{
	if(!limit)
		limit = v;

	if(!(v & 1))
	{
		int d2 = 0;
		do
		{
			v >>= 1;
			++d2;
		}
		while(!(v & 1));
		
		r.push_back(make_pair((Tp)2, (Te)d2));
	}
	
	if(v == 1)
		return v;

	if(is_prime(v))
	{
		r.push_back(make_pair((Tp)v, (Te)1));
		return (T)1;
	}
	
	for(T i = 3; i < limit; i += 2)
	{
		if((v % i) == 0)
		{
			int d = 0;
			do
			{
				v /= i;
				++d;
			}
			while((v % i) == 0);
			
			r.push_back(make_pair((Tp)i, (Te)d));
			if(v == 1)
				return v;
			
			if(is_prime(v))
			{
				r.push_back(make_pair((Tp)v, (Te)1));
				return (T)1;
			}
		}
	}
	
	return v;
}

// prime modulus assumed
template<typename T = unsigned>
struct mod_t
{
	T m;
	vector<T> _fact; // automatically computed by fact
	vector<T> _inv; // must use fast_inv
	vector<pair<T, int> > _phi; // automatically computed by phi, prim_root, exp, log
	bool _phi_done;
	T _prim_root; // automatically computed by prim_root, exp, log
	vector<T> _exp; // must use fast_exp for mul and exp, but automatically computed by log
	vector<T> _log; // must use fast_exp for mul, automatically computed by log
	T _exp_lim;
	bool _exp_done;

	mod_t(T m)
	: m(m), _phi_done(false), _prim_root(0), _exp_lim(0), _exp_done(false)
	{
		assert(m >= 0);
		assert(is_prime(m));
		
		_inv.push_back(0);
		_inv.push_back(1);
	}
	
	const vector<pair<T, int> >& phi()
	{
		if(!_phi_done)
		{
			factor(m - 1, _phi);
			_phi_done = true;
		}
		return _phi;
	}
	
	template<typename Ta>
	T operator ()(Ta a)
	{
		return mod(a, m);
	}
	
	template<typename Ta>
	bool is_prim_root(Ta ap)
	{
		T a = mod(ap, m);
		if(a == 0)
			return false;
		if(a == 1)
			return m == 2;
		if(a == (m - 1))
			return m == 3;
		
		phi();
		
		for(int k = 0; k < (int)_phi.size(); ++k)
		{
			if(modrpow(a, (m - 1) / _phi[k].first, m) == 1)
				return false;
		}
		
		return true;
	}
	
	T prim_root()
	{
		if(!_prim_root)
		{
			for(int i = 1; i < m; ++i)
			{
				if(is_prim_root(i))
				{
					_prim_root = i;
					break;
				}
			}
		}
		return _prim_root;
	}
	
	T eexp(T a)
	{
		if(a < _exp_lim)
			return _exp[a];
		else
			return modrpow(prim_root(), a, m);
	}
	
	template<typename Ta>
	T zexp(Ta a)
	{
		return eexp(mod(a, m - 1));
	}

	T rlog(T s)
	{
		if(_log.empty())
		{
			_log.resize(m + 1, m);
			_log[0] = m - 1;
		}
		
		T r = _log[s];
		
		if(r == m)
		{
			assert(!_exp_done);
			T pr = prim_root();
			T v;
			if(_exp_lim)
				v = modrmul(_exp[_exp_lim - 1], pr, m);
			else
				v = (T)1;
			
			T old_lim = _exp_lim;
			T stop = m - 1;
			for(;;)
			{
				_log[v] = _exp_lim;
				_exp.push_back(v);
				++_exp_lim;
				
				if(_exp_lim >= stop)
					break;
					
				if(v == s)
				{
					stop = min(old_lim * 2, stop);
				}

				v = modrmul(v, pr, m);
			}
			
			if(_exp_lim == (m - 1))
				_exp_done = true;
				
			r = _log[s];
		}
		
		return r;
	}
	
	void fast_exp()
	{
		rlog(m);
	}
	
	template<typename Ta>
	T zlog(Ta a)
	{
		return rlog(mod(a, m));
	}

	T rmul(T a, T b)
	{
		if(!_exp_done)
			return modrmul(a, b, m);

		if(!a || !b)
			return 0;
		else
			return _exp[modradd(_log[a], _log[b], m - 1)];
	}
	
	template<typename Ta, typename Tb>
	T zmul(Ta a, Tb b)
	{
		return rmul(mod(a, m), mod(b, m));
	}
	
	T rdiv(T a, T b)
	{
		if(!_exp_done)
			return modrmul(a, rinv(b), m);
			
		if(!a || !b)
			return 0;
		else
			return _exp[modrsub(_log[a], _log[b], m - 1)];
	}
		
	template<typename Ta, typename Tb>
	T zdiv(Ta a, Tb b)
	{
		return rdiv(mod(a, m), mod(b, m));
	}
	
	T rpow(T a, T b)
	{
		if(!_exp_done)
			return modrpow(a, b, m);

		if(!a)
			return 0;
		else
			return _exp[modrmul(_log[a], b, m - 1)];
	}
		
	template<typename Ta, typename Tb>
	T zpow(Ta a, Tb b)
	{
		return rpow(mod(a, m), mod(b, m - 1));
	}
	
	T rinv_(T a)
	{
		return _exp_done ? _exp[modrneg(_log[a], m -1)] : modrinv(a, m);
	}
	
	void fast_inv(T n)
	{
		T stop = min(m, max((T)(_inv.size() * 2), n + 1));
		for(T i = _inv.size(); i < stop; ++i)
		{
			_inv.push_back(rinv_(i));
		}
	}
	
	void fast_inv()
	{
		fast_inv(m);
	}
	
	T rinv(T a)
	{
		if(a < (T)_inv.size())
			return _inv[a];
		else
		{
			if((m - a) < (T)_inv.size())
				return modrneg(_inv[m - a], m);
			else
				return rinv_(a);
		}
	}

	template<typename Ta>
	T zinv(Ta a)
	{
		return rinv(mod(a, m));
	}
	
	T rfact(T a)
	{
		if(a >= (T)_fact.size())
		{
			typedef typename integer_comp_traits<T>::t Tc;
			Tc f;
			if(_fact.size())
				f = (Tc)_fact.back();
			else
			{
				f = (Tc)1;
				_fact.push_back((T)1);
			}
			int lim = min(m, max((T)(_fact.size() * 2), a + 1));
			for(T i = _fact.size(); i < lim; ++i)
			{
				f *= (Tc)i;
				f %= (Tc)m;
				_fact.push_back((T)f);
			}
		}
		
		return _fact[a];
	}

	template<typename Ta>
	T zfact(Ta a)
	{
		if(a < 0 || !lessthanu(a, m))
			return (T)0;
		else
			return rfact((T)a % m);
	}
	
	template<typename Tn, typename Tk>
	T binomp(Tn n, Tk k)
	{
		typedef typename integer_comp_traits<T>::t Tc;
		Tc r = (Tc)1;
		T logr = (T)0;
		
		for(;;)
		{
			T nr = modp(n, m);
			T kr = modp(k, m);
		
			if(nr < kr)
				return (T)0;
			
			if(nr != kr)
			{
				T nf = rfact(nr);
				T kf = rfact(kr);
				T nkf = rfact(nr - kr);
				if(_exp_done)
					logr = modradd(logr, modrsub(_log[nf], modradd(_log[kf], _log[nkf], m - 1), m - 1), m -1);
				else
				{
					r *= (Tc)nf;
					r %= (Tc)m;
					r *= (Tc)rinv(modrmul(kf, nkf, m));
					r %= (Tc)m;
				}
			}

			if(lessthanu(k, m))
				break;

			n /= (Tn)m;
			k /= (Tk)m;
		}

		if(_exp_done)
			r = _exp[logr];
		
		return (T)r;
	}
	
	template<typename Tn, typename Tk>
	T binom(Tn n, Tk k)
	{
		assert(n >= 0);
		
		if(!lethanu(k, n) || k < 0)
			return (T)0;
		
		return binomp(n, k);
	}
	
	void fast()
	{
		fast_exp();
		fast_inv();
	}
	
	void precompute()
	{
		fast();
		rfact(m - 1);
	}
};

struct escape_barrier;

struct escape_exception : public std::exception
{
	const escape_barrier& _barrier;
	escape_exception(const escape_barrier& barrier) : _barrier(barrier) {}
	const escape_barrier& barrier() const {return _barrier;}
};

struct escape_barrier
{
	int _enabled;
	escape_barrier() : _enabled(0) {}
	void enable() {++_enabled;}
	void disable() {--_enabled;}
	void operator()() const
	{
		if(_enabled)
			throw escape_exception(*this);
	}
};

#define CATCH_ESCAPE(e, s) try {(e).enable(); s;} catch(const escape_exception& __ex) {(e).disable(); if(&__ex.barrier() != &(e)) throw;} catch(...) {(e).disable(); throw;}

template < typename Vertex, typename Queue, typename CBDiscover, typename Escape >
class simple_bfs_visitor : public default_bfs_visitor {
public:
	size_t _dist;
	const Queue& _queue;
	const CBDiscover& _cb_discover;
	const Escape& _escape;
	Vertex _last;
	
	simple_bfs_visitor(const Escape& escape, const Queue& queue, const CBDiscover& cb_discover) : _dist(0), _queue(queue), _cb_discover(cb_discover), _escape(escape)
	{ }
	
	template < typename Graph >
	void finish_vertex(Vertex u, const Graph & g)
	{
		if(u == _last && !_queue.empty())
		{
			_last = _queue.back();
			++_dist;
		}
	}
	
	template < typename Graph >
	void discover_vertex(Vertex u, const Graph & g)
	{
		if(!_cb_discover(u, _dist))
			_escape();

		if(!_dist)
		{
			_last = u;
			++_dist;
		}
	}
};

template <class VertexListGraph, class CBDiscover, class ColorMap>
void simple_breadth_first_search(const VertexListGraph& g, typename graph_traits<VertexListGraph>::vertex_descriptor s, const CBDiscover& cb_discover, ColorMap color)
{
	queue<typename graph_traits<VertexListGraph>::vertex_descriptor> q;
	escape_barrier escape;
	simple_bfs_visitor<typename graph_traits<VertexListGraph>::vertex_descriptor, queue<typename graph_traits<VertexListGraph>::vertex_descriptor>, CBDiscover, escape_barrier> vis(escape, q, cb_discover);
	CATCH_ESCAPE(escape, breadth_first_search(g, s, q, vis, color));
}

template <class VertexListGraph, class CBDiscover>
void simple_breadth_first_search(const VertexListGraph& g, typename graph_traits<VertexListGraph>::vertex_descriptor s, const CBDiscover& cb_discover)
{
	std::vector<default_color_type> color_vec(num_vertices(g));
	simple_breadth_first_search(g, s, cb_discover, make_iterator_property_map(color_vec.begin(), get(vertex_index, g), white_color));
}


    template <typename CBDiscover, typename Escape >
    class simple_dfs_visitor : public dfs_visitor<>
    {
    public:
      simple_dfs_visitor(const Escape& escape, const CBDiscover& cb_discover)
        : _escape(escape), _cb_discover(cb_discover) {}

      template <class Vertex, class Graph>
      void discover_vertex(Vertex u, Graph&) {
        if(!_cb_discover(u))
        	_escape();
      }
    protected:
      const CBDiscover& _cb_discover;
      int& _count;
	const Escape& _escape;
    };
    
    template <typename CBDiscover, typename Escape >
    class simple_dfs_cc_visitor : public dfs_visitor<>
    {
    public:
      simple_dfs_cc_visitor(const Escape& escape, const CBDiscover& cb_discover, 
                          int& c_count)
        : _escape(escape), _cb_discover(cb_discover), _count(c_count) {}

      template <class Vertex, class Graph>
      void start_vertex(Vertex, Graph&) {
        if (_count == (std::numeric_limits<int>::max)())
          _count = 0; // start counting components at zero
        else
          ++_count;
      }
      
      template <class Vertex, class Graph>
      void discover_vertex(Vertex u, Graph&) {
        if(!_cb_discover(u, _count))
        	_escape();
      }
    protected:
      const CBDiscover& _cb_discover;
      int& _count;
	const Escape& _escape;
    };

 template <class Graph, class CBDiscover, class P, class T, class R>
  inline int
  simple_dfs(const Graph& g, CBDiscover cb_discover, 
                       const bgl_named_params<P, T, R>& params)
  {
    if (num_vertices(g) == 0) return 0;

    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    typedef typename boost::graph_traits<Graph>::directed_category directed;
    BOOST_STATIC_ASSERT((boost::is_same<directed, undirected_tag>::value));

    // c_count initialized to "nil" (with nil represented by (max)())
    int c_count((std::numeric_limits<int>::max)());
    escape_barrier escape;
    simple_dfs_cc_visitor<CBDiscover, escape_barrier> vis(escape, cb_discover, c_count);
    CATCH_ESCAPE(escape, depth_first_search(g, params.visitor(vis)));
    return c_count + 1;
  }

  template <class Graph, class CBDiscover>
  inline int
  simple_dfs(const Graph& g, CBDiscover cb_discover)
  {
    if (num_vertices(g) == 0) return 0;

    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    typedef typename boost::graph_traits<Graph>::directed_category directed;
    BOOST_STATIC_ASSERT((boost::is_same<directed, undirected_tag>::value));

    // c_count initialized to "nil" (with nil represented by (max)())
    int c_count((std::numeric_limits<int>::max)());
    escape_barrier escape;
    simple_dfs_cc_visitor<CBDiscover, escape_barrier> vis(escape, cb_discover, c_count);
    CATCH_ESCAPE(escape, depth_first_search(g, visitor(vis)));
    return c_count + 1;
  }

 template <class Graph, class Vertex, class CBDiscover, class P, class T, class R>
  inline void
  simple_dfs(const Graph& g, Vertex v, CBDiscover cb_discover, 
                       const bgl_named_params<P, T, R>& params)
  {
    escape_barrier escape;
    simple_dfs_visitor<CBDiscover, escape_barrier> vis(escape, cb_discover);
    CATCH_ESCAPE(escape, depth_first_visit(g, params.visitor(vis).root_vertex(v)));
  }

  template <class Graph, class Vertex, class CBDiscover>
  inline void
  simple_dfs(const Graph& g, Vertex v, CBDiscover cb_discover)
  {
    escape_barrier escape;
    simple_dfs_visitor<CBDiscover, escape_barrier> vis(escape, cb_discover);
    CATCH_ESCAPE(escape, depth_first_visit(g, v, vis));
  }

#define eps 1e-11

template<typename T>
typename integer_comp_traits<T>::t cross(T x0, T y0, T x1, T y1)
{
	typedef typename integer_comp_traits<T>::t Tm;
	return (Tm)x0 * (Tm)y1 - (Tm)x1 * (Tm)y0;
}

template<typename T>
typename integer_comp_traits<T>::t direction(T x0, T y0, T x1, T y1, T x2, T y2)	
{
	return cross(x2 - x0, y2 - y0, x1 - x0, y1 - y0);
}

template<typename T>
bool on_segment(T x0, T y0, T x1, T y1, T x2, T y2)
{
	return (min(x0, x1) <= x2 && x2 <= max(x0, x1)) && (min(y0, y1) <= y2 && y2 <= max(y0, y1));
}

template<typename T>
bool segments_intersect(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4)
{
	typename integer_comp_traits<T>::t d1 = direction(x3, y3, x4, y4, x1, y1);
	typename integer_comp_traits<T>::t d2 = direction(x3, y3, x4, y4, x2, y2);
	typename integer_comp_traits<T>::t d3 = direction(x1, y1, x2, y2, x3, y3);
	typename integer_comp_traits<T>::t d4 = direction(x1, y1, x2, y2, x4, y4);
	
	if(
		(((d1 > 0) && (d2 < 0)) || ((d1 < 0) && (d2 > 0))) &&
		(((d3 > 0) && (d4 < 0)) || ((d3 < 0) && (d4 > 0))) )
		return true;

	if(d1 == 0 && on_segment(x3, y3, x4, y4, x1, y1))
		return true;

	if(d2 == 0 && on_segment(x3, y3, x4, y4, x2, y2))
		return true;

	if(d3 == 0 && on_segment(x1, y1, x2, y2, x3, y3))
		return true;

	if(d4 == 0 && on_segment(x1, y1, x2, y2, x4, y4))
		return true;
		
	return false;
}



ifstream in;
ofstream out;

void init();
void solve_case(int casen);

int main(int argc, char** argv)
{
	if(argv[1])
	{
		in.open(argv[1]);
		if(argv[2])
		{
			out.open(argv[2]);
		}
		else
		{
			out.open("/dev/stdout");
		}
	}
	else
	{
		in.open("/dev/stdin");
		out.open("/dev/stdout");
	}

	init();

	int cases;
	in >> cases;
	
	for(int i = 0; i < cases; ++i)
		solve_case(i);
	
	return 0;
}




void init()
{
	
}

#define M 1000000009LL

int n;
int k;
#define edges edges_
vector<int> edges[512];

s64 choose(int a, int b)
{
	s64 r = 1LL;
	for(int i = 0; i < b; ++i)
	{
//		r = (r * (s64)(i + 1)) % M;
		r = (r * (s64)(a - i)) % M;
	}
	return r;
}

s64 go(int v, int p)
{
//	cerr << v << ' ' << p << endl;
	int a = ((p != -1) ? (edges[p].size()) : 0);
//	cerr << "KA " << k - a << ' ' << edges[v].size() - (v != 0) << endl;
	s64 r = choose(k - a, edges[v].size() - (v != 0));
	for(int i = 0; i < edges[v].size(); ++i)
	{
		if(edges[v][i] == p)
			continue;
		r = (r * go(edges[v][i], v)) % M;
	}
//	cerr << r << endl;
	return r;
}

void solve_case(int casen)
{
	in >> n >> k;
	for(int i = 0; i < 512; ++i)
		edges[i].clear();
	for(int i = 0; i < n - 1; ++i)
	{
		int a, b;
		in >> a >> b;
		--a; --b;
//		cerr << a << "->" << b << endl;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	out << "Case #" << (casen + 1) << ": " << go(0, -1) << endl;
}

