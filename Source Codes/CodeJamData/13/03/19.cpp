#include <string>
#include <iostream>

/*
Using the BigInteger Library
https://mattmccutchen.net/bigint/
*/
#include "BigIntegerLibrary.hh"

BigInteger powers[101];
BigInteger numbers[100000];
int cnt = 0;
int check(BigInteger x) {
  std::string s1 = bigIntegerToString(x), s2 = s1;
  std::reverse(s1.begin(),s1.end());
  return s1 == s2;
}

FILE *fout = fopen("palindromes.txt","w");

void save(BigInteger x) {
  numbers[cnt] = x;
  cnt++;
  int i;
  std::string s1 = bigIntegerToString(x);
  for(i=0;i<s1.size();i++) fprintf(fout,"%c",s1[i]);
  fprintf(fout,"\n");
}

void f(BigInteger x, int len, int cur) {
  if(2*cur > len) return;
  f(x,len,cur+1);
  BigInteger next;
  if(2*cur == len) next = x+powers[cur];
  else next = x+powers[len-cur]+powers[cur];
  if( check(next*next) && next*next < powers[100] ) {
    save(next*next);
    //std::cout<<next<<std::endl;
    f(next,len,cur);
  }
}

int main() {
	try {
		int maxPower = 100;
		BigInteger x(1), big10(10);
		for (int power = 0; power <= maxPower; power++) {
      powers[power] = x;
      x *= big10;
		}
		for(int i=0;i<50;i++) {
      printf("%d %d\n",i,cnt);
      f(0,i,0);
    }
	} catch(char const* err) {
		std::cout << "The library threw an exception:\n" << err << std::endl;
	}
	printf("%d\n",cnt);
  getchar();
	return 0;
}
