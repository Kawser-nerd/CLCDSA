
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
//#include "gmp.h"
#include "ttmath\ttmathuint.h"
#include <boost/math/common_factor_rt.hpp>

#define USE_CPPSTREAM 1
#ifdef USE_CPPSTREAM
std::istream& GetIStream(int argc, const char* argv[]) {
  if(argc<2) return std::cin;
  static std::ifstream fin(argv[1]);
  assert(fin);
  return fin;
}
std::ostream& GetOStream(int argc, const char* argv[]) {
  if(argc<3) return std::cout;
  static std::ofstream fout(argv[2]);
  assert(fout);
  return fout;
}
#else
FILE* GetIStream(int argc, const char* argv[]) {
  if(argc<2) return stdin;
  FILE* fin=fopen(argv[1],"rt");
  assert(fin);
  return fin;
}
FILE* GetOStream(int argc, const char* argv[]) {
  if(argc<3) return stdout;
  FILE* fout=fopen(argv[2],"wb");
  assert(fout);
  return fout;
}
#endif

typedef ttmath::UInt<6> big_uint_t;
typedef ttmath::UInt<6> vbig_uint_t;

int N; // [2,1000]
big_uint_t Ti[1000];
//big_uint_t dTi[1000];

void ComputePGCD(big_uint_t& a, const big_uint_t& b) {
  a=boost::math::gcd(a,b);
}

void ProcessTestCase(vbig_uint_t& res) {
  big_uint_t pgcd=Ti[1]<Ti[0]?Ti[0]-Ti[1]:Ti[1]-Ti[0];
  big_uint_t dTi;
  for(int i=2; i<N; ++i) {
    dTi = Ti[i]<Ti[0]?Ti[0]-Ti[i]:Ti[i]-Ti[0];
    ComputePGCD(pgcd,dTi);
    if(pgcd==1) { res=0; return; }
  }
  res = pgcd-(Ti[0]-1)%pgcd-1;
}


int main(int argc, const char* argv[]) {
  
#if USE_CPPSTREAM
  std::istream& in = GetIStream(argc,argv);
  std::ostream& out = GetOStream(argc,argv);

  int C; // <=100
  in >> C;
  for(int i=0; i<C; ++i) {
    in >> N;
    for(int j=0; j<N; ++j) in >> Ti[j];

    vbig_uint_t res;
    ProcessTestCase(res);  

    out << "Case #" << (i+1) <<": " << res << std::endl;
  }


#else
  FILE* in = GetIStream(argc,argv);
  FILE* out = GetOStream(argc,argv);
  /*
  for(int j=0; j<1000; ++j) {
    mpz_init (Ti[j]);
  }
  */

  int C; // <=100
  fscanf(in,"%i",&C);
  for(int i=0; i<C; ++i) {
    fscanf(in,"%i",&N);
    for(int j=0; j<N; ++j) //mpz_inp_str(Ti[j],in,10);
      /*
    mpz_t res;
    mpz_init(res);
    ProcessTestCase(res);  
    */

    fprintf(out, "Case #%i: ", i+1);
    /*
    mpz_out_str(out,10,res);
    mpz_clear (res);
    */
  }

#endif


  return 0;
}

