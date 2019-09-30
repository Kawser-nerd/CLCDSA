#include <iostream>
#include <string> 
#include <cassert> 
#define NDEBUG
#ifdef NDEBUG
#define DBG(x) 
#else
#define DBG(x) x
#endif

using namespace std;

void readandsolve(int cse){
  int s,q;
  char trash;
  cin >> s;
  cin.ignore(1);
  string *engines = new string[s];
  for( int i=0; i<s; ++i){
    char *buffer = new char[1023];
    cin.getline(buffer,1023);
    engines[i] = buffer;
    DBG(cout << i << " " << engines[i] << endl;)
  }
  cin >> q;
  cin.ignore(1);
  int *indices = new int[q];
  for( int i=0; i<q; ++i){
    char *buffer = new char[1023];
    cin.getline(buffer,1023);  
    indices[i] = -1;
    for(int j=0; j<s; ++j){
      if(engines[j] == string(buffer)){
	indices[i] = j;
	break;
      }
    }
    assert(indices[i] >= 0);
  }

  int **solve = new int*[q+1];
  for (int i=0; i<=q; ++i)
    solve[i] = new int[s];
  
  for( int i=0; i<s; ++i){
    solve[q][i] = 0;
  }

  for(int j=q-1; j>=0; --j){
    int min=0x7FFFF;
    int minindex = -1;
    for (int i=0; i<s; ++i){
      if(min >= solve[j+1][i]){
	min = solve[j+1][i];
      }
    }
    
    for( int i=0; i<s; ++i){
      // update 
      if(indices[j] == i){
	solve[j][i] = 0x7FFFF; // don't start here! 
      }
      else if(solve[j+1][i] == min){
	solve[j][i] = min; // don't switch 
      }
      else{
	solve[j][i] = min+1; // switch
      }
    }
  }

  int ans = 0x7FFFF;
  for(int i=0; i<s; ++i){
    ans = (ans < solve[0][i] ? ans : solve[0][i]);
  }
  
  cout << "Case #" << cse << ": " << ans << endl; 
}

int main(){
  int n;
  cin >> n;
  for (int i=0; i<n; ++i){
    readandsolve(i+1);
  }
  return 0; 
}
