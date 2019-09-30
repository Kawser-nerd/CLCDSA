#define NDEBUG

#pragma GCC optimize("-O3,inline,omit-frame-pointer,unroll-loops")

#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

#include <memory>
#include <cassert>

#include <functional>
#include <chrono>
#include <bitset>

using namespace std;

namespace ValLib {

	const int MOD = 1000000007;

	typedef unsigned long long ull;

	template<typename Key, typename Value>
	using umap = std::unordered_map<Key, Value>;
	template<typename T>
	using uset = std::unordered_set<T>;
	template <typename T>
	using sptr = typename std::shared_ptr<T>;
	class vnode;
	class vegde;
	class vgraph;

	class NullStream {
	public:
		template<typename T> NullStream& operator<<(T const&) { return *this; }
	};

#ifdef NDEBUG
#define vcerr if(false) NullStream()
#define vendl nullptr
#else
#define vcerr std::cerr
#define vendl std::endl
#endif

	template<typename T>
	void fill(vector<T>& vec, const T& value) {
		std::fill(vec.begin(), vec.end(), value);
	}
	template<typename T>
	void fill(vector<vector<T>>& vec, const T& value) {
		for (vector<T>& t : vec) std::fill(t.begin(), t.end(), value);
	}
	template<typename T>
	void resize(vector<vector<T>>& vec, int size1, int size2) {
		vec.resize(size1);
		for (vector<T>& t : vec) t.resize(size2);
	}
	template <typename T>
	const typename vector<T>::const_iterator max_element(const vector<T>& vec) {
		assert(!vec.empty());
		return std::max_element(vec.begin(), vec.end());
	}
	template <typename T, typename _Pr>
	const typename vector<T>::const_iterator max_element(const vector<T>& vec, _Pr lessThan) {
		assert(!vec.empty());
		return std::max_element(vec.begin(), vec.end(), lessThan);
	}
	template <typename T>
	const typename vector<T>::const_iterator min_element(const vector<T>& vec) {
		assert(!vec.empty());
		return std::min_element(vec.begin(), vec.end());
	}
	template <typename T, typename _Pr>
	const typename vector<T>::const_iterator min_element(const vector<T>& vec, _Pr lessThan) {
		assert(!vec.empty());
		return std::min_element(vec.begin(), vec.end(), lessThan);
	}
	int accumulate(const vector<int>& vec) {
		return std::accumulate(vec.begin(), vec.end(), 0);
	}
	template <typename _Pr>
	int accumulate(const vector<int>& vec, _Pr func) {
		return std::accumulate(vec.begin(), vec.end(), 0, func);
	}
	double accumulate(const vector<double>& vec) {
		return std::accumulate(vec.begin(), vec.end(), 0.0);
	}
	template <typename _Pr>
	double accumulate(const vector<double>& vec, _Pr func) {
		return std::accumulate(vec.begin(), vec.end(), 0.0, func);
	}
	float accumulate(const vector<float>& vec) {
		return std::accumulate(vec.begin(), vec.end(), 0.f);
	}
	template <typename _Pr>
	float accumulate(const vector<float>& vec, _Pr func) {
		return std::accumulate(vec.begin(), vec.end(), 0.f, func);
	}
	template <typename T, typename _Pr>
	bool all_of(const vector<T>& vec, _Pr pred) {
		return std::all_of(vec.begin(), vec.end(), pred);
	}
	template <typename T, typename _Pr>
	bool any_of(const vector<T>& vec, _Pr pred) {
		return std::any_of(vec.begin(), vec.end(), pred);
	}
	template <typename T, typename _Pr>
	bool none_of(const vector<T>& vec, _Pr pred) {
		return std::none_of(vec.begin(), vec.end(), pred);
	}
	template <typename T>
	const typename vector<T>::const_iterator find(const vector<T>& vec, const T& val) {
		return std::find(vec.begin(), vec.end(), val);
	}
	template <typename T, typename _Pr>
	const typename vector<T>::const_iterator find_if(const vector<T>& vec, _Pr pred) {
		return std::find_if(vec.begin(), vec.end(), pred);
	}
	template <typename T>
	bool contains(const vector<T>& vec, const T& val) {
		return std::find(vec.begin(), vec.end(), val) != vec.end();
	}
	template <typename T, typename _Pr>
	bool contains_if(const vector<T>& vec, _Pr pred) {
		return std::find_if(vec.begin(), vec.end(), pred) != vec.end();
	}
	template <typename T, typename _Pr>
	typename iterator_traits<const typename vector<T>::const_iterator>::difference_type count_if(const vector<T>& vec, _Pr pred) {
		return std::count_if(vec.begin(), vec.end(), pred);
	}

	template<typename T, size_t N>
	void fill(array<T, N>& ary, const T& value) {
		std::fill(ary.begin(), ary.end(), value);
	}
	template<typename T, size_t N, size_t M>
	void fill(array<array<T, M>, N>& ary, const T& value) {
		for (array<T, M>& t : ary) std::fill(t.begin(), t.end(), value);
	}
	template <typename T, size_t N, typename _Pr>
	const typename array<T, N>::const_iterator max_element(const array<T, N>& ary) {
		assert(!ary.empty());
		return std::max_element(ary.begin(), ary.end());
	}
	template <typename T, size_t N, typename _Pr>
	const typename vector<T>::const_iterator max_element(const array<T, N>& ary) {
		assert(!ary.empty());
		return std::max_element(ary.begin(), ary.end());
	}
	template <typename T, size_t N, typename _Pr>
	const typename array<T, N>::const_iterator max_element(const array<T, N>& ary, _Pr lessThan) {
		assert(!ary.empty());
		return std::max_element(ary.begin(), ary.end(), lessThan);
	}
	template <typename T, size_t N, typename _Pr>
	const typename array<T, N>::const_iterator min_element(const array<T, N>& ary) {
		assert(!ary.empty());
		return std::min_element(ary.begin(), ary.end());
	}
	template <typename T, size_t N, typename _Pr>
	const typename array<T, N>::const_iterator min_element(const array<T, N>& ary, _Pr lessThan) {
		assert(!ary.empty());
		return std::min_element(ary.begin(), ary.end(), lessThan);
	}
	template <size_t N>
	int accumulate(const array<int, N>& ary) {
		return std::accumulate(ary.begin(), ary.end(), 0);
	}
	template <size_t N, typename _Pr>
	int accumulate(const array<int, N>& ary, _Pr func) {
		return std::accumulate(ary.begin(), ary.end(), 0, func);
	}
	template <size_t N>
	double accumulate(const array<double, N>& ary) {
		return std::accumulate(ary.begin(), ary.end(), 0.0);
	}
	template <size_t N, typename _Pr>
	double accumulate(const array<double, N>& ary, _Pr func) {
		return std::accumulate(ary.begin(), ary.end(), 0.0, func);
	}
	template <size_t N>
	float accumulate(const array<float, N>& ary) {
		return std::accumulate(ary.begin(), ary.end(), 0.f);
	}
	template <size_t N, typename _Pr>
	float accumulate(const array<float, N>& ary, _Pr func) {
		return std::accumulate(ary.begin(), ary.end(), 0.f, func);
	}
	template <typename T, size_t N, typename _Pr>
	bool all_of(const array<T, N>& ary, _Pr pred) {
		return std::all_of(ary.begin(), ary.end(), pred);
	}
	template <typename T, size_t N, typename _Pr>
	bool any_of(const array<T, N>& ary, _Pr pred) {
		return std::any_of(ary.begin(), ary.end(), pred);
	}
	template <typename T, size_t N, typename _Pr>
	bool none_of(const array<T, N>& ary, _Pr pred) {
		return std::none_of(ary.begin(), ary.end(), pred);
	}
	template <typename T, size_t N>
	const typename array<T, N>::const_iterator find(const array<T, N>& ary, const T& val) {
		return std::find(ary.begin(), ary.end(), val);
	}
	template <typename T, size_t N, typename _Pr>
	const typename array<T, N>::const_iterator find_if(const array<T, N>& ary, _Pr pred) {
		return std::find_if(ary.begin(), ary.end(), pred);
	}
	template <typename T, size_t N>
	bool contains(const array<T, N>& ary, const T& val) {
		return std::find(ary.begin(), ary.end(), val) != ary.end();
	}
	template <typename T, size_t N, typename _Pr>
	bool contains_if(const array<T, N>& ary, _Pr pred) {
		return std::find_if(ary.begin(), ary.end(), pred) != ary.end();
	}
	template <typename T, size_t N, typename _Pr>
	typename iterator_traits<const typename array<T, N>::const_iterator>::difference_type count_if(const array<T, N>& ary, _Pr pred) {
		return std::count_if(ary.begin(), ary.end(), pred);
	}

	template<typename Key, typename Value>
	bool containsKey(const umap<Key, Value>& m, const Key& key) {
		return m.find(key) != m.end();
	}
	template<typename Key, typename Value>
	bool containsValue(const umap<Key, Value>& m, const Value& val) {
		for (auto it = m.begin(); it != m.end(); ++it)
			if (it->second == val)
				return true;
		return false;
	}
	template<typename T>
	const typename uset<T>::const_iterator find(const uset<T>& s, const T& key) {
		return s.find(key);
	}
	template<typename T>
	bool contains(const uset<T>& s, const T& key) {
		return s.find(key) != s.end();
	}

	void test() {
		vector<int> v = {};
		bool c = contains(v, 2);
		int x = count_if(v, [](int y) { return y <= 0; });
		cout << x << endl;

		uset<int> s;
		s.insert(1);
		s.insert(4);
		s.insert(1);
		s.insert(2);
		bool bb = contains(s, 1);
		cout << bb << endl;
		bb = contains(s, 3);
		cout << bb << endl;

		umap<int, string> m;
		m[0] = "a";
		m[4] = "b";
		m[2] = "c";
		auto au = m.find(4);
		if (au != m.end()) {
			string val = (*au).second;
		}
		bool b = containsKey(m, 1);
		cout << b << endl;
		b = containsKey(m, 3);
		cout << b << endl;
		b = containsValue(m, string("a"));
		cout << b << endl;
		b = containsValue(m, string("d"));
		cout << b << endl;

		getchar();
		getchar();
	}

	class Point {
	public:

		Point() = default;

		//inline Point() :
		//x(-1),
		//y(-1)
		//{}

		inline Point(int _x, int _y) :
			x(_x),
			y(_y)
		{}

		static Point getDistance(const Point& p1, const Point& p2) {
			return move(Point(abs(p1.x - p2.x), abs(p1.y - p2.y))); 
		}

		void setPos(const Point& pos) { x = pos.x; y = pos.y; }
		void setPos(int x, int y) { this->x = x; this->y = y; }

		Point operator+ (const Point &p) const { return move(Point(x + p.x, y + p.y)); }
		Point operator- (const Point &p) const { return move(Point(x - p.x, y - p.y)); }
		void operator+= (const Point &p) { x += p.x; y += p.y; }
		void operator-= (const Point &p) { x -= p.x; y -= p.y; }
		bool operator== (const Point &p) const { return x == p.x && y == p.y; }
		bool operator!= (const Point &p) const { return x != p.x || y != p.y; }
		//bool operator<(const Point &p) const {return x * x + y * y < p.x * p.x + p.y * p.y;}
		const Point& getPos() const { return *this; }

		string to_string() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

		int x;
		int y;
	};

	/// <summary>
	/// ????????
	/// </summary>
	class UnionFind {
	public:

		/// <summary>
		/// ???????
		/// </summary>
		/// <param name="N">???</param>
		UnionFind(int N) {
			parent.resize(N);
			for (int i = 0; i < N; ++i) {
				parent[i] = i;
			}
		}

		/// <summary>
		/// ??x?????
		/// </summary>
		/// <param name="x">????????(0?N-1)</param>
		/// <returns>??x??(0?N-1)</returns>
		int find(int x) {
			if (parent[x] == x) {
				return x;
			} else {
				parent[x] = find(parent[x]); // ????(???????root??????)
				return parent[x];
			}
		}

		/// <summary>
		/// ???????????
		/// </summary>
		/// <param name="x1">?????????(0?N-1)</param>
		/// <param name="x2">?????????(0?N-1)</param>
		/// <returns>true: ???, false: ????</returns>
		bool same(int x1, int x2) {
			return find(x1) == find(x2);
		}

		/// <summary>
		/// ????????????
		/// </summary>
		/// <param name="x1">?????(0?N-1)</param>
		/// <param name="x2">?????(0?N-1)</param>
		void union_elements(int x1, int x2) {
			int rootX1 = find(x1);
			int rootX2 = find(x2);
			parent[rootX2] = rootX1;
		}

	private:
		vector<int> parent;

	};

	class vmath {
	public:

		// ???????? O(?n)
		static ull calcDivisors(list<ull>* divisors, ull n) {
			divisors->clear();
			if (n <= 0ull) {
				return 0ull;
			}
			divisors->push_back(1ull);
			if (n != 1ull) {
				divisors->push_back(n);
			}
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					divisors->push_back(i);
					if (i != n / i) {
						divisors->push_back(n / i);
					}
				}
			}
			return divisors->size();
		}

		// ???????? O(?n)
		static ull calcDivisorNum(ull n) {
			if (n <= 0ull) {
				return 0ull;
			}
			ull count = 1ull; // for 1
			if (n != 1ull) {
				++count; // for n
			}
			// for 2?n-1
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					count += 1ull;
					if (i != n / i) {
						count += 1ull;
					}
				}
			}
			return count;
		}

		// ????? O(?n)
		static int calcDecompositPrime(list<ull>* primes, ull n) {
			primes->clear();
			if (n == 0) {
				return 0ull;
			}
			if (n == 1) {
				primes->push_back(1);
				return 1ull;
			}
			// ???????
			ull a = 2ull;
			// ?n ? a ( n ? a * a ) ???????
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a ????????a ????
					primes->push_back(a);
					// ?????????? a ???
					n /= a;
				} else {
					// a ??????????? a ? 1 ?????
					a++;
				}
			}
			primes->push_back(n);
			return primes->size();
		}

		// ???????? O(?n)
		static ull calcDecompositPrimeNum(ull n) {
			if (n <= 1) {
				return n;
			}
			ull count = 0ull;
			// ???????
			ull a = 2ull;
			// ?n ? a ( n ? a * a ) ???????
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a ????????a ????
					++count;
					// ?????????? a ???
					n /= a;
				} else {
					// a ??????????? a ? 1 ?????
					a++;
				}
			}
			++count; // for n
			return count;
		}

		// ??
		static ull fact(ull x) {
			if (x == 0ull) {
				return 1ull;
			} else {
				return x * fact(x - 1ull);
			}
		}

		// ?? nPr
		static ull permutation(int n, int r) {
			assert(n >= r);
			//return fact(n) / fact(n - r);
			ull result = 1;
			for (ull i = n; i > n - r; --i) {
				result *= i;
			}
			return result;
		}

		// ????? nCr
		// ??makePascalTriangle?????????????????????
		static ull combination(int n, int r) {
			assert(n >= r);
			assert(n <= mPascalTriangleDepth);
			return mPascalTriangle[n][r];
		}

		// ????? nHr = n+r-1Cr
		// ??????n??r???????????????????????
		// 4??5????????a=2,b=0,c=2,d=1??????||??|????????
		// ?????|???????????????n,????r-1??????n+r-1
		// (n-r)?????????n+r-1Pr???????r????????nHr = n+r-1Cr
		static ull repeatedCombination(int n, int r) {
			return combination(n + r - 1, r);
		}

		// ?????????????????????????????????????????
		static void makePascalTriangle(int depth) {
			resize(mPascalTriangle, depth + 1, depth + 1);
			for (int i = 0; i <= depth; ++i) {
				mPascalTriangle[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					mPascalTriangle[i][j] = mPascalTriangle[i - 1][j] + mPascalTriangle[i - 1][j - 1];
				}
			}
			mPascalTriangleDepth = depth;
		}

		// x?N????????
		static ull getNDigitNumber(ull x, ull n) {
			return (x / pow(10ull, n - 1ull)) % 10;
		}

		// x?N????????
		static int getNDigitNumber(int x, int n) {
			assert(n <= 10);
			return (x / pow(10, n - 1)) % 10;
		}

		// x?N?????(?????) O(logN)
		static ull pow(ull x, ull n) {
			assert(x >= 0ull);
			assert(n >= 0ull);
			if (x == 0ull) {
				if (n == 0ull) {
					return 1ull;
				} else {
					return 0ull;
				}
			}
			ull result = 1ull;
			ull z = x;
			while (n > 0ull) {
				if (n & 1ull) {
					result *= z;
				}
				z *= z;
				n >>= 1;
			}
			return result;
		}

		// x?N?????(?????) O(logN)
		static int pow(int x, int n) {
			assert(x >= 0);
			assert(n >= 0);
			if (x == 0) {
				if (n == 0) {
					return 1;
				} else {
					return 0;
				}
			}
			int result = 1;
			int z = x;
			while (n > 0) {
				if (n & 1) {
					result *= z;
				}
				z *= z;
				n >>= 1;
			}
			return result;
		}

	private:
		static int mPascalTriangleDepth;
		static vector<vector<ull>> mPascalTriangle;
	};
	int vmath::mPascalTriangleDepth = 0;
	vector<vector<ull>> vmath::mPascalTriangle;

	class vmath_mod {
	public:

		// ??
		static ull fact(ull x) {
			ull result = 1ull;
			for (ull i = 1ull; i <= x; ++i) {
				result *= i;
				result %= MOD;
			}
			return result;
		}

		// ?? nPr
		static ull permutation(int n, int r) {
			assert(n >= r);
			//return fact(n) / fact(n - r);
			ull result = 1;
			for (ull i = n; i > n - r; --i) {
				result *= i;
				result %= MOD;
			}
			return result;
		}

		// ????? nCr
		// ??makePascalTriangle?????????????????????
		static ull combination(int n, int r) {
			assert(n >= r);
			assert(n <= mPascalTriangleDepth);
			return mPascalTriangle[n][r];
		}

		// ????? nHr = n+r-1Cr
		// ??????n??r???????????????????????
		// 4??5????????a=2,b=0,c=2,d=1??????||??|????????
		// ?????|???????????????n,????r-1??????n+r-1
		// (n-r)?????????n+r-1Pr???????r????????nHr = n+r-1Cr
		static ull repeatedCombination(int n, int r) {
			return combination(n + r - 1, r);
		}

		// ?????????????????????????????????????????
		static void makePascalTriangle(int depth) {
			resize(mPascalTriangle, depth + 1, depth + 1);
			for (int i = 0; i <= depth; ++i) {
				mPascalTriangle[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					mPascalTriangle[i][j] = (mPascalTriangle[i - 1][j] + mPascalTriangle[i - 1][j - 1]) % MOD;
				}
			}
			mPascalTriangleDepth = depth;
		}

		// x?N????????
		static ull getNDigitNumber(ull x, ull n) {
			return (x / pow(10ull, n - 1ull)) % 10;
		}

		// x?N????????
		static int getNDigitNumber(int x, int n) {
			assert(n <= 10);
			return (x / pow(10, n - 1)) % 10;
		}

		// x?N????? O(n)
		static ull pow(ull x, ull n) {
			if (x == 0ull) {
				if (n == 0ull) {
					return 1ull;
				} else {
					return 0ull;
				}
			}
			ull result = 1ull;
			for (ull i = 0ull; i < n; ++i) {
				result *= x;
				result %= MOD;
			}
			return result;
		}

		// x?N????? O(n)
		static int pow(int x, int n) {
			assert(x >= 0);
			assert(n >= 0);
			if (x == 0) {
				if (n == 0) {
					return 1;
				} else {
					return 0;
				}
			}
			int result = 1;
			for (int i = 0; i < n; ++i) {
				result *= x;
				result %= MOD;
			}
			return result;
		}

	private:
		static int mPascalTriangleDepth;
		static vector<vector<ull>> mPascalTriangle;
	};
	int vmath_mod::mPascalTriangleDepth = 0;
	vector<vector<ull>> vmath_mod::mPascalTriangle;

	class vegde {
	public:
		vegde() : vegde(-1) {

		}

		vegde(int cost) :
			mCost(cost) {

		}

		int getCost() const { return mCost; }

	private:
		int mCost;
	};

	class vnode {
	public:
		vnode() : vnode(-1) {

		}

		vnode(int id) :
			mID(id) {

		}

		void addEgde(const vegde& egde, const vnode* node) {
			mEgdeList.emplace_back(egde, node);
		}
		void removeEgde(int nodeID) {
			auto itrNewEnd = std::remove_if(mEgdeList.begin(), mEgdeList.end(), [=](const pair<vegde, const vnode*>& p)->bool {
				return (p.second->getID() == nodeID);
			});
			mEgdeList.erase(itrNewEnd, mEgdeList.end());
		}

		int getID() const { return mID; }
		const list<pair<vegde, const vnode*>>& getEgde() const { return mEgdeList; }
	private:
		list<pair<vegde, const vnode*>> mEgdeList;
		int mID;
	};

	class AdjacencyMatrix {
	public:

		AdjacencyMatrix() = default;

		AdjacencyMatrix(int nodeNum) {
			resize(mConnectionMap, nodeNum, nodeNum);
			resize(mCostMap, nodeNum, nodeNum);
			resize(mMinimumDistMap, nodeNum, nodeNum);
		}

		//virtual void addEdge(int nodeID1, int nodeID2, int cost) = 0;
		//virtual void removeEgde(int nodeID1, int nodeID2) = 0;

		void warshallFloyd(int nodeNum) {
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						if (mConnectionMap[i][j]) {
							mMinimumDistMap[i][j] = mCostMap[i][j];
						} else {
							mMinimumDistMap[i][j] = 99999999;
						}
					}
				}
			}
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						mMinimumDistMap[i][j] = min(mMinimumDistMap[i][j], mMinimumDistMap[i][k] + mMinimumDistMap[k][j]);
					}
				}
			}
			//for (int i = 0; i < mNodeNum; ++i) {
			//	for (int j = 0; j < mNodeNum; ++j) {
			//		cerr << mMinimumDistMap[i][j] << ", ";
			//	}
			//	cerr << endl;
			//}
		}

		const vector<vector<bool>>& getConnectionMap() const { return mConnectionMap; }
		const vector<vector<int>>& getCostMap() const { return mCostMap; }

		const vector<vector<int>>& getMinimumDistMap() const { return mMinimumDistMap; }

	protected:
		vector<vector<bool>> mConnectionMap;
		vector<vector<int>> mCostMap;

		vector<vector<int>> mMinimumDistMap;
	};

	class DirectedAdjacencyMatrix : public AdjacencyMatrix  {
	public:

		DirectedAdjacencyMatrix() = default;

		DirectedAdjacencyMatrix(int nodeNum) :
			AdjacencyMatrix(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mConnectionMap[nodeID1][nodeID2] = true;
			mCostMap[nodeID1][nodeID2] = cost;
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mConnectionMap[nodeID1][nodeID2] = false;
			mCostMap[nodeID1][nodeID2] = 0;
		}
	};

	class UndirectedAdjacencyMatrix : public AdjacencyMatrix {
	public:

		UndirectedAdjacencyMatrix() = default;

		UndirectedAdjacencyMatrix(int nodeNum) :
			AdjacencyMatrix(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mConnectionMap[nodeID1][nodeID2] = true;
			mConnectionMap[nodeID2][nodeID1] = true;
			mCostMap[nodeID1][nodeID2] = cost;
			mCostMap[nodeID2][nodeID1] = cost;
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mConnectionMap[nodeID1][nodeID2] = false;
			mConnectionMap[nodeID2][nodeID1] = false;
			mCostMap[nodeID1][nodeID2] = 0;
			mCostMap[nodeID2][nodeID1] = 0;
		}

	};

	// ???
	class vgraph {
	public:

		const int INF = 1000000;

		vgraph(int nodeNum) {
			mNodeNum = nodeNum;
			mNodes.resize(nodeNum);
			for (int i = 0; i < nodeNum; ++i) {
				mNodes[i] = move(vnode(i));
			}
			mMinimumDists.resize(mNodeNum);
			mPrevNodes.resize(mNodeNum);
		}

		void addEgde(int nodeID1, int nodeID2) {
			addEgde(nodeID1, nodeID2, 1);
		}

		virtual void addEgde(int nodeID1, int nodeID2, int cost) = 0;
		virtual void removeEgde(int nodeID1, int nodeID2) = 0;

		int dfs(int start) {
			vector<bool> check(mNodes.size());
			fill(check, false);
			int MAX_DEPTH = INF; // ???????????????
			return dfsSub(start, check, MAX_DEPTH, 0);
		}

		void bfs(int start) {
			vector<bool> check(mNodes.size());
			fill(check, false);
			int MAX_DEPTH = INF; // ???????????????
			return bfsSub(start, check, MAX_DEPTH);
		}

		// ??????????????????????????????????
		// start????????????????????????false???
		// ?????????????????????????????????
		// O(V*E)
		bool bellmanFord(int start) {

			vector<int>& dist = mMinimumDists;

			fill(dist, INF);
			dist[start] = 0;

			for (int i = 0; i < mNodeNum; ++i) {
				bool update = false;
				for (vnode node : mNodes) {
					for (const pair<vegde, const vnode*> egde : node.getEgde()) {
						int from = node.getID();
						int to = egde.second->getID();
						if (dist[from] == INF) {
							continue;
						}
						if (dist[from] + egde.first.getCost() < dist[to]) {
							dist[to] = dist[from] + egde.first.getCost();
							update = true;

							if (i == mNodeNum - 1) {
								//return false;
							}
						}
					}
				}
				if (!update) {
					break;
				}
			}
			return true;
		}

		// ????????????????????????????????
		// ????????????????????????????
		// O(E*logV)
		void dijkstraSearch(int start) {

			// Minimum distances for each nodes
			vector<int>& dpMinDists = mMinimumDists;
			fill(dpMinDists, INF);

			// Result of the previous visited node
			vector<int>& resultPrev = mPrevNodes;
			fill(resultPrev, -1);

			// Create a priority_queue for search.
			typedef pair<int, int> P; // key: ???????????, value: ?????
			priority_queue<P, vector<P>, greater<P>> pq_node;

			// Mark the current node as visited and enqueue it
			pq_node.push(P(0, start));

			dpMinDists[start] = 0;

			while (!pq_node.empty()) {
				P p = pq_node.top();
				pq_node.pop();
				int nowDist = p.first;
				int nowNodeID = p.second;

				if (dpMinDists[nowNodeID] < nowDist) {
					continue;
				}

				for (const pair<vegde, const vnode*>& egde : mNodes[nowNodeID].getEgde()) {
					const vnode* nextNode = egde.second;
					int nextNodeID = nextNode->getID();

					int nextNodeDist = nowDist + egde.first.getCost();
					if (nextNodeDist < dpMinDists[nextNodeID]) {
						dpMinDists[nextNodeID] = nextNodeDist;
						resultPrev[nextNodeID] = nowNodeID;

						pq_node.push(P(nextNodeDist, nextNodeID));
					}
				}
			}
		}

		int calcMaxDepth() const {
			pair<int, int> farestNodeData = getFarestNodeID(0);
			pair<int, int> farestNodeData2 = getFarestNodeID(farestNodeData.first);
			return farestNodeData2.second;
		}

		int getNodeNum() const { return mNodeNum; }
		const vector<vnode>& getNodes() const { return mNodes; }

		const vector<int>& getMinimumDists() const { return mMinimumDists; }
		const vector<int>& getPrevNodes() const { return mPrevNodes; }
	protected:

		int dfsSub(int nodeIndex, vector<bool>& check, int MAX_DEPTH, int depth) {
			check[nodeIndex] = true;
			int result = 0;

			// ????????
			if (depth < MAX_DEPTH) {
				for (auto t : mNodes[nodeIndex].getEgde()) {
					if (check[t.second->getID()]) {
						// ??????????
						continue;
					}
					result += dfsSub(t.second->getID(), check, MAX_DEPTH, depth + 1);
				}
			}

			// ??????
			result += 1; // ???????????????????????????+1??


			check[nodeIndex] = false;

			return result;
		}

		void bfsSub(int start, vector<bool>& check, int MAX_DEPTH) {

			queue<pair<int, int>> target;
			target.push(pair<int, int>(start, 0));
			while (!target.empty()) {
				pair<int, int> now = target.front();
				target.pop();

				// ??????????????????????
				//mNodes[now.first].something = someData;

				check[now.first] = true;
				int egdeCount = 0;
				if (now.second < MAX_DEPTH) {
					for (const pair<vegde, const vnode*>& egde : mNodes[now.first].getEgde()) {
						if (check[egde.second->getID()]) {
							// ??????????????????????????
							continue;
						}
						++egdeCount;
						target.push(pair<int, int>(egde.second->getID(), now.second + 1));
					}
				}
				if (now.second == MAX_DEPTH || egdeCount == 0) {
					// ???????????????????????????

					// doSomething.

				}
			}
		}

		// ?????????????????????id??????
		// ?????????????????????????(??????)
		pair<int, int> getFarestNodeID(int start) const {
			queue<pair<int, int>> q; // nodeID, ??????????
			q.push(make_pair(start, 0));
			pair<int, int> finalNodeData;
			vector<bool> opened(mNodeNum);
			fill(opened, false);
			while (!q.empty()) {
				pair<int, int> nodeData = q.front();
				int nodeID = nodeData.first;
				int dist = nodeData.second;
				if (dist > finalNodeData.second) {
					finalNodeData.second = dist;
					finalNodeData.first = nodeID;
				}
				q.pop();
				for (const pair<vegde, const vnode*> egde : mNodes[nodeID].getEgde()) {
					int id = egde.second->getID();
					if (opened[id]) {
						continue;
					}
					opened[id] = true;
					q.push(make_pair(id, dist + egde.first.getCost()));
				}
			}
			return finalNodeData;
		}

		int mNodeNum;
		bool mUseMaps;
		vector<vnode> mNodes;

		vector<int> mMinimumDists;
		vector<int> mPrevNodes;
	};

	// ????? UnDirected Val Graph.
	class udvgraph : public vgraph {
	public:
		udvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)), &mNodes[nodeID2]);
			mNodes[nodeID2].addEgde(move(vegde(cost)), &mNodes[nodeID1]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
			mNodes[nodeID2].removeEgde(nodeID1);
		}
	};

	// ??????????????????????????? UnDirected Val Graph Matrix
	class udvgraph_m : public udvgraph {
	public:

		udvgraph_m(int nodeNum) :
			udvgraph(nodeNum) {
			mAdjacencyMatrix = UndirectedAdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			udvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			udvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
	private:
		UndirectedAdjacencyMatrix mAdjacencyMatrix;
	};


	// ????? Directed Val Graph.
	class dvgraph : public vgraph {
	public:
		dvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)),&mNodes[nodeID2]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
		}

		// ???????????????
		list<int> searchStartNodes() const {
			list<int> startNodes;
			unordered_map<int, int> nodesInputs; // key:?????, value:??????
			for (auto node : mNodes) {
				for (auto edge : node.getEgde()) {
					++nodesInputs[edge.second->getID()];
				}
			}
			for (int i = 0; i < mNodeNum; ++i) {
				if (nodesInputs.find(i) == nodesInputs.end()) {
					startNodes.push_back(i);
				}
			}
			return move(startNodes);
		}
	};

	// ??????????????????????????? Directed Val Graph Matrix
	class dvgraph_m : public dvgraph {
	public:

		dvgraph_m(int nodeNum) :
			dvgraph(nodeNum) {
			mAdjacencyMatrix = DirectedAdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			dvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			dvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
	private:
		DirectedAdjacencyMatrix mAdjacencyMatrix;
	};

	class Timer {
	public:
		Timer(const Timer&) = delete;
		Timer& operator=(const Timer&) = delete;
		Timer(Timer&&) = delete;
		Timer& operator=(Timer&&) = delete;
		static Timer& getInstance() {
			static Timer timer;
			return timer;
		}

		void setSize(int size) { mTimes.resize(size); mStopWatches.resize(size); }
		void startTimer(int index) { mStopWatches[index] = chrono::system_clock::now(); }
		void stopTimer(int index) { mTimes[index] += chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - mStopWatches[index]).count(); }
		void addTime(int index, long long millisec) { mTimes[index] += millisec; }
		void resetTimes() { fill(mTimes, 0LL); }
		void resetTime(int index) { mTimes[index] = 0LL; }
		long long getTime(int index) { return mTimes[index]; }
		void outputTimes() { outputTimes(0, mTimes.size()); }
		void outputTimes(int startIndex, int endIndex) {
			for (int i = startIndex; i <= endIndex; ++i) {
				cerr << "Time[" << i << "]: " << mTimes[i] << endl;
			}
		}
	private:
		Timer() {
			mTimes.resize(100);
			mStopWatches.resize(100);
			resetTimes();
		}
		~Timer() = default;

		vector<long long> mTimes;
		vector<chrono::system_clock::time_point> mStopWatches;
	};

	// ?????????????
	static int bitcount8(unsigned char b8) {
		// 8 bits ???????????????
		//c_assert( 8 == (CHAR_BIT * sizeof( b8 )) );

		b8 = (unsigned char)( ((b8 & 0xAA) >> 1) + (b8 & 0x55) );
		b8 = (unsigned char)( ((b8 & 0xCC) >> 2) + (b8 & 0x33) );
		b8 = (unsigned char)( ((b8 & 0xF0) >> 4) + (b8 & 0x0F) );

		return b8;
	}

	// ?????????????
	static int bitcount16(unsigned short w16) {
		// 16 bits ???????????????
		//c_assert( 16 == (CHAR_BIT * sizeof( w16 )) );

		w16 = (unsigned short)( ((w16 & 0xAAAA) >> 1) + (w16 & 0x5555) );
		w16 = (unsigned short)( ((w16 & 0xCCCC) >> 2) + (w16 & 0x3333) );
		w16 = (unsigned short)( ((w16 & 0xF0F0) >> 4) + (w16 & 0x0F0F) );
		w16 = (unsigned short)( ((w16 & 0xFF00) >> 8) + (w16 & 0x00FF) );

		return w16;
	}

	// ?????????????
	static int bitcount32(unsigned long dw32) {
		// 32 bits ???????????????
		//c_assert( 32 == (CHAR_BIT * sizeof( dw32 )) );

		dw32 = ((dw32 & 0xAAAAAAAA) >>  1) + (dw32 & 0x55555555);
		dw32 = ((dw32 & 0xCCCCCCCC) >>  2) + (dw32 & 0x33333333);
		dw32 = ((dw32 & 0xF0F0F0F0) >>  4) + (dw32 & 0x0F0F0F0F);
		dw32 = ((dw32 & 0xFF00FF00) >>  8) + (dw32 & 0x00FF00FF);
		dw32 = ((dw32 & 0xFFFF0000) >> 16) + (dw32 & 0x0000FFFF);

		return dw32;
	}

	// ????????????index???
	// ????????-1???
	// ?????: int result = binarySearch<int>(A, 0, N - 1, [=](int x) { return x >= K; });
	template<typename T> int binarySearch(const vector<T>& vec, int beginIndex, int endIndex, const function<bool(T)>& confilm) {
		// ?????????????????????????????????
		int lb = beginIndex - 1; // lower bound
		int ub = endIndex + 1; // upper bound

		while (ub - lb > 1) {
			int mid = (ub + lb) / 2;
			if (confilm(vec[mid])) {
				ub = mid;
			} else {
				lb = mid;
			}
		}

		if (ub == endIndex + 1) {
			// ???
			return -1;
		}

		return ub;
	}

}

using namespace ValLib;

int main()
{
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<unsigned long> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<array<int, 20>> bitAcc(N + 1);
	bitAcc[0] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < N; ++i) {
		bitset<20> bs(A[i]);
		for (int b = 0; b < 20; ++b) {
			bitAcc[i + 1][b] = bitAcc[i][b] + (bs[b] ? 1 : 0);
		}
	}

	ull ans = 0ull;
	
	// i = j ????????
	ans += (ull)N;

	for (int i = 1; i < N; ++i) {

		int index = binarySearch<array<int, 20>>(bitAcc, i, N,
			[&](const array<int, 20>& x) {

			// ????????????
			for (int b = 0; b < 20; ++b) {
				if (x[b] - bitAcc[i - 1][b] > 1) {
					return true;
				}
			}
			return false;
		});
		
		if (index < 0) {
			index = N + 1;
		}

		index--;
		if (index <= i) {
			continue;
		}

		ull width  = (ull)(index - i + 1);
		//ans += width * (width - 1ull) / 2ull;
		ans += width - 1ull;

	}
	
	cout << ans << endl;

	//getchar();
	//getchar();
}