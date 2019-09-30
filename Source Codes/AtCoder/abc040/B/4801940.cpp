#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class Set{
  public:
    Set(): x( 1), y( 1), v( 1), m( 0){}
    Set( int64_t x, int64_t v): x( 1), y( 1), v( 1), m( 0){ set( x, v); }
    ~Set(){}
    bool operator< ( const Set& set) const{ return eval()< set.eval()? true: false; }
    bool operator> ( const Set& set) const{ return set< *this; }
    void set( int64_t x, int64_t v){
      this->x= x;
      this->v= v;
      y= v/ x;
      m= v- x* y;
    }
    int64_t eval() const{ return m+ abs((double)(x- y)); }
    void print() const{ clog<< v<< " = "<< x<< " * "<< y<< " + "<< m<< " -> "<< eval()<<endl; }
  private:
    int64_t x;
    int64_t y;
    int64_t v;
    int64_t m;
};
int main(){
  int n; cin>> n;
  vector< Set> sets;
  for( int i= 0; i< sqrt( n+ 1); i++){
    if( !i) continue;
    sets.push_back( Set( i, n));
  }
  //sort( sets.begin(), sets.end(), greater<Set>());
  sort( sets.begin(), sets.end());
  for( auto itr= sets.begin(); itr!= sets.end(); itr++){ itr->print(); }
  cout<< sets.begin()->eval();

  return 0;
}