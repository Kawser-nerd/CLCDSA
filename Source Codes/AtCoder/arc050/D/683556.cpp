#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

/*  
 * Implementation of a simple range minimum query algorithm described in
 * S. Alstrup, C. Gavoille, H. Kaplan, T. Rauhe.
 * Nearest common ancestors: a survey and a new distributed algorithm,
 * In Proc. 14th annual ACM symposium on Parallel algorithms and architectures, 258-264, 2002.
 *
 * Copyright (C) 2005 Hideo Bannai (http://tlas.i.kyushu-u.ac.jp/~bannai/)
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef RMQ_H_
#define RMQ_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Type for array index.
 * Assumes at leat 32 bits.
 * Hasn't been tested with 64 bits */
typedef unsigned int INT;

/* Type for values in the array. */
typedef unsigned int VAL;	

/* compare the value inside the array */
#define VAL_LT(x,y) x < y

/* a struct to hold preprocessed information */

struct rmqinfo {
  INT alen;     // length of original array
  VAL * array;  // pointer to original array
  INT ** sparse;
  INT * block_min;
  INT * labels;
};

/*
 * Return the position in array which gives the minimum value
 * in the subarray a[x..y] using a naive algorithm
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query_naive(VAL * a, INT x, INT y);

/*
 * Preprocess array in linear time so that range minimum
 * queries can be conducted in constant time.
 */
struct rmqinfo * rm_query_preprocess(VAL * a, INT alen);


/*
 * Return the position in array which gives the minimum value 
 * in the subarray rmqinfo.array[x..y] using preprocessed information.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query(const struct rmqinfo * info, INT x, INT y);

/*
 * Free all memory associated with rmqinfo EXCEPT the original array
 */
void rm_free(struct rmqinfo * info);

#ifdef __cplusplus
}
#endif

#endif /*RMQ_H_*/


#include <stdio.h>
#include <stdlib.h>

/* clear the least significant x-1 bits */
static inline INT clearbits(INT n, INT x){
  return((n >> x) << x);  
}

/* return floor of log n. assumes n > 0
 * uses __builtin_clz for GCC */
static inline INT intlog2(INT n){
// #ifdef __GNUC__
  return(__builtin_clz(n)^31);
// #else
//   INT res;
//   for(res = 0; n > 0; n >>= 1, res++);
//   return(res-1);
// #endif
}

/*
 * return position of least significant set bit. assumes n > 0
 * uses __builtin_ctz for GCC */
static inline INT lsbset (INT n){
// #ifdef __GNUC__
  return(__builtin_ctz(n));
// #else
//   INT res = 0;
//   while(n % 2 == 0){
//     res++; n >>= 1;
//   }
//   return(res);
// #endif
}

/*
 * Return the position in array which gives the minimum value
 * in the subarray a[x..y] using a naive algorithm.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query_naive(VAL * a, INT x, INT y){
  INT z, tmp;
  VAL minval;
  if(x == y) return x;
  if(x > y){
    tmp = x; x = y; y = tmp;
  }
  z = x;
  minval = a[x];  
  for(x++; x <= y; x++){
    if(VAL_LT(a[x],minval)){
      z = x; minval = a[x];
    }
  }
  return(z);
}

/*
 * Preprocess array in linear time so that range minimum
 * queries can be conducted in constant time.
 */
struct rmqinfo * rm_query_preprocess(VAL * array, INT alen){
  struct rmqinfo * info;
  INT i, j, g, rows, cols, block_cnt, rowelmlen;
  INT *block_min, **sparse, *labels;
  INT gstack[32], gstacksize = 0;
  // info = (struct rmqinfo *) malloc(sizeof(struct rmqinfo));
  info = new rmqinfo;
  /* divide input array into blocks of size 32.
   * block_cnt is the number of such blocks.
   * block_minpos is an array that contains the 
   * minimum positions in each block. */
  block_cnt = ((alen-1) >> 5) + 1;
  block_min = new INT[block_cnt];
  for(i = j = 0; i < alen; i++){
    if(i % 32 == 0){
      if(i > 0) j++;
      block_min[j] = i;
    } else if(VAL_LT(array[i],array[block_min[j]])){
      block_min[j] = i;
    }
  }
  /* make a sparse table for the rmq of the blocks.
   * sparse[j][i] represents the minimum in
   * block[i] to block[i + 2^{j+1} - 1] */
  rows = intlog2(block_cnt);
  sparse = NULL;
  /* sparse tables aren't needed when the array is less than 32 elements long */
  if(rows > 0){
    // sparse = (INT **) malloc (sizeof(INT *) * rows);
    sparse = new INT*[rows];
    /* first row is min of adjacent entries. Table entries are
     * converted to positions in original array */
    // sparse[0] = (INT *) malloc (sizeof(INT) * (block_cnt - 1));
    sparse[0] = new INT[block_cnt - 1];
    for(i = 0; i < block_cnt - 1; i++){
      if(VAL_LT(array[block_min[i+1]],array[block_min[i]]))
        sparse[0][i] = block_min[i+1];
      else
        sparse[0][i] = block_min[i];
    }
    for(j = 1; j < rows; j++){
      rowelmlen = 2 << j;    /* 2^{j+1} */
      cols = block_cnt - rowelmlen + 1;
      // sparse[j] = (INT *) malloc (sizeof(INT) * cols);
      sparse[j] = new INT[cols];
      for(i = 0; i < cols; i++){
        if(VAL_LT(array[sparse[j-1][i + (rowelmlen >> 1)]],array[sparse[j-1][i]]))
          sparse[j][i] = sparse[j-1][i + (rowelmlen >> 1)];
        else
          sparse[j][i] = sparse[j-1][i];  
      }
    }
  }
  
  /* create integers for constant time rmq inside the blocks
   * In each block:
   * - g[i]: the first position to the left of i
   * where array[g[i]] < array[i] (or -1 if there is no such position).
   * - l[i]: the jth bit of l[i] is 1 iff j is the first
   * position left of i where array[j] < array[i] */
  // labels = (INT *) malloc(sizeof(INT) * alen);
  labels = new INT[alen];
  for(i = 0; i < alen; i++){
    if(i % 32 == 0) gstacksize = 0;
    labels[i] = 0;
    while(gstacksize > 0 && (VAL_LT(array[i],array[gstack[gstacksize-1]]))){
      gstacksize--;
    }
    if(gstacksize > 0){
      g = gstack[gstacksize-1];
      labels[i] = labels[g] | (1 << (g%32));
    }
    gstack[gstacksize++] = i;
  }
  info->array = array;
  info->sparse = sparse;
  info->block_min = block_min;
  info->labels = labels;
  info->alen = alen;
  return info;  
}


/*
 * Return the position in array which gives the minimum value
 * in the subarray rmqinfo.array[x..y] using preprocessed information.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query(const struct rmqinfo * info, INT l, INT r){
  INT blocknum_l, blocknum_r, blockdiff, blockmin;
  INT tmp, v, bpos;
  INT v1, v2, pos1, pos2;
  if(l == r) return l;
  if(l > r){
    tmp = l; l = r; r = tmp;
  }
  blocknum_l = (l >> 5); blocknum_r = (r >> 5);  /* obtain which blocks l and r will come in */
  bpos = blocknum_l << 5;
  switch(blockdiff = blocknum_r - blocknum_l){
  case 0: /* one inblock query in block blocknum_l. from position (l%32) to (r%32) */
    v = clearbits(info->labels[r], l % 32); /* clear (x - 1) insiginificant bits */
    return ((v == 0) ? r : bpos + lsbset(v));
    break;
  case 1:  /* two inblock queries. in block blocknum_l and blocknum_r.
      * in blocknum_l: postion (l%32) to 31  
      * in blocknum_r: postion 0 to (r%32) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
    break;
  default: /* two inblock queries, and a query over the blocks.
      * in blocknum_l: postion (l%32) to 31
      * in blocknum_r: postion 0 to (r%32).
      * block (blocknum_l+1) to (blonum_r-1) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    if(blockdiff == 2){ /* (blocknum_l+1) == (blonum_r-1) */
      blockmin = info->block_min[blocknum_l+1];
    } else {
      /* rmq of blocknum_l+1 to blocknum_r-1 */
      int t1, t2, k;
      k = intlog2(blockdiff-1) - 1;
      t1 = info->sparse[k][blocknum_l+1];
      t2 = info->sparse[k][blocknum_r - (1 << (k+1))];
      blockmin = (VAL_LT(info->array[t2],info->array[t1])) ? t2 : t1;
    }
    pos1 = (VAL_LT(info->array[blockmin],info->array[pos1])) ? blockmin : pos1;
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
  }
}

void rm_free(struct rmqinfo * info){
  INT block_cnt, rows;
  int i;
  block_cnt = ((info->alen-1) >> 5) + 1;
  rows = intlog2(block_cnt);
  for(i = 0; i < rows; i++){
    delete[] info->sparse[i];
  }
  delete[] (info->sparse);
  delete[] (info->block_min);
  delete[] (info->labels);
  delete (info);
}



class charSA{
    unsigned char mask[8] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
    #define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
    #define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
    #define chr(i) (cs==sizeof(int)?((unsigned int*)s)[i]:((unsigned char *)s)[i])
    #define isLMS(i) (i>0 && tget(i) && !tget(i-1))

    // find the start or end of each bucket
    void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, sum = 0;
        for (i = 0; i <= K; i++)
            bkt[i] = 0; // clear all buckets
        for (i = 0; i < n; i++)
            bkt[chr(i)]++; // compute the size of each bucket
        for (i = 0; i <= K; i++) {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }
    // compute SAl
    void induceSAl(unsigned int *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
        for (i = 0; i < n; i++) {
            j = SA[i] - 1;
            if (j >= 0 && !tget(j))
                SA[bkt[chr(j)]++] = j;
        }
    }
    // compute SAs
    void induceSAs(unsigned int *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
        for (i = n - 1; i >= 0; i--) {
            j = SA[i] - 1;
            if (j >= 0 && tget(j))
                SA[--bkt[chr(j)]] = j;
        }
    }
    // find the suffix array SA of s[0..n-1] in {1..K}^n
    // require s[n-1]=0 (the sentinel!), n>=2
    // use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
    void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
        // cout<<"SA_IS "<<n<<" "<<K<<" "<<0<<endl;
        int i, j;
        // unsigned int *t = (unsigned int *) malloc(n / 8 + 1); // LS-type array in bits
        unsigned int *t = new unsigned int[n / 8 + 1]; // LS-type array in bits
        assert(t!=NULL);
        // Classify the type of each character
        tset(n-2, 0);
        tset(n-1, 1); // the sentinel must be in s1, important!!!
        for (i = n - 3; i >= 0; i--)
            tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
        // stage 1: reduce the problem by at least 1/2
        // sort all the S-substrings
        int *bkt = new int[K+1]; // bucket array
        getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
        for (i = 0; i < n; i++)
            SA[i] = -1;
        for (i = 1; i < n; i++){
            if (isLMS(i)){
                SA[--bkt[chr(i)]] = i;
            }
        }
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        // compact all the sorted substrings into the first n1 items of SA
        // 2*n1 must be not larger than n (proveable)
        int n1 = 0;
        for (i = 0; i < n; i++)
            if (isLMS(SA[i]))
                SA[n1++] = SA[i];
        // find the lexicographic names of all substrings
        for (i = n1; i < n; i++)
            SA[i] = -1; // init the name array buffer
        int name = 0, prev = -1;
        for (i = 0; i < n1; i++) {
            int pos = SA[i];
            bool diff = false;
            for (int d = 0; d < n; d++)
                if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                    diff = true;
                    break;
                } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                    break;
            if (diff) {
                name++;
                prev = pos;
            }
            pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
            SA[n1 + pos] = name - 1;
        }
        for (i = n - 1, j = n - 1; i >= n1; i--)
            if (SA[i] >= 0)
                SA[j--] = SA[i];
        // stage 2: solve the reduced problem
        // recurse if names are not yet unique
        int *SA1 = SA, *s1 = SA + n - n1;
        if (name < n1){
            SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
        }
        else{
            // generate the suffix array of s1 directly
            for (i = 0; i < n1; i++)
                assert(s1[i]>=0),SA1[s1[i]] = i;
        }
        // stage 3: induce the result for the original problem
        // put all left-most S characters into their buckets
        getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
        for (i = 1, j = 0; i < n; i++)
            if (isLMS(i))
                s1[j++] = i; // get p1
        for (i = 0; i < n1; i++)
            SA1[i] = s1[SA1[i]]; // get index in s
        for (i = n1; i < n; i++)
            SA[i] = -1; // init SA[n1..n-1]
        for (i = n1 - 1; i >= 0; i--) {
            j = SA[i];
            SA[i] = -1;
            SA[--bkt[chr(j)]] = j;
        }
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        delete[] bkt;
        delete[] t;
    }
public:
    // constructor
    charSA(){
    }
    vector<int> buildCharSA(string &u, int K, int cs = 1){
        int n = u.size();
        int *sa = new int[n+1]; // integer sequence
        unsigned char* s = (unsigned char *) u.c_str();
        SA_IS(s, sa, n + 1, K, cs);
        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            ret[i]=sa[i+1];
        }
        delete[] sa;
        return ret;
    }
};
vector<int> calc_lcp(const vector<int> &sa, const string &s){
    int n = s.size();
    vector<int> lcp(n);
    vector<int> rank(n,0);
    for (int i = 1; i < n; i++){
        rank[sa[i-1]] = i;
    }
    for(int i = 0, h = 0; i < n; i++) {
        if(rank[i] < n - 1) {
            for (int j = sa[rank[i]]; s[i + h] == s[j + h]; ++h);
            lcp[rank[i]] = h;
            if (h > 0){
                --h;
            }
        }
    }
    lcp[n - 1]=0;
    for (int i = 0; i < n; i++){
        if(s[sa[n-1] + i] != s[sa[n-2] + i]) break;
        lcp[n - 1]++;
    }
    return lcp;
}


int n;
string s;
vint v;
vint Rank;
rmqinfo *info;

int queryLCE(int x, int y){
	if(x == y) return n - x;
    return info -> array[rm_query(info, min(Rank[x], Rank[y]) + 1, max(Rank[x], Rank[y]))];
}

bool comp(int a,int b){
	int aa = n-a;
	int bb = n-b;
	if(a<b){
		return !comp(b,a);
	}
	// cout<<a<<" "<<b<<endl;
	int t = queryLCE(a,b);
	// cout<<"t "<<t<<endl;
	if(t >= aa){
		t = queryLCE(b,b+aa);
		if(t >= bb-aa){
			t = queryLCE(b+bb-aa,a);
			if(t == aa){
				return false;
			}
			else{
				return s[b+bb-aa+t] < s[a+t];
			}
		}
		else{
			return s[b+t] < s[b+aa+t];
		}
	}
	else{
		return s[a+t] < s[b+t];
	}
}


void mainmain(){
	cin>>n;
	cin>>s;
	charSA t;
	vint SA = t.buildCharSA(s,256,1);
	vector<int> LCP = calc_lcp(SA,s);
    VAL *tarr = new VAL[LCP.size()];
    Rank = vector<int>(SA.size());
    for(int i = 0; i < LCP.size(); i++){
        tarr[i] = LCP[i];
        Rank[SA[i]] = i;
    }
    for(int i = 0; i < LCP.size(); i++){
        tarr[i] = LCP[i];
    }
    info = rm_query_preprocess(tarr, LCP.size());
	v=vint(n);
	rep(i,n){
		v[i]=i;
	}
	sort(ALL(v),comp);
	rep(i,n){
		cout<<v[i]+1<<endl;
	}
	// cout<<comp(1,2)<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}