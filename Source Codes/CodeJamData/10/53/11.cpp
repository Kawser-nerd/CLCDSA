#include <iostream>
#include <map>
using namespace std;

bool DEBUG = false;
/*
So:
 when a vendor arrives at a in range [a-k,a+l]:
  a = 3, k = 3, l = 9
 you get two new ranges of [a-(k+1)..a+(l-k-1)] and [a+(l-k+1)..a+l+1]
*/
map<int, int> m;
long long sc;

void init(){
  m.clear();
  sc = 0;
}

void display(){
  if (!DEBUG)
    return;
  for (map<int,int>::iterator w = m.begin(); w != m.end(); ++w)
    printf("%d -> %d\n", w->first, w->second); 
  printf("-\n");
}

void explode(int a, int k, int l){
  if (DEBUG)
    printf("Explode(%d, %d, %d)\n", a, k, l);
  display();
  // Insert a 1 at a-(k+1)
  if (m.find(a-(k+1)) != m.end()){
    assert(m[a-(k+1)] == -1);
    m.erase(a-(k+1));
  } else {
    m[a-(k+1)] = 1;
  }
  assert(m[a-k] == 1);
  m.erase(a-k);				   
  display();
  // Insert a 1 at a+l+1
  assert(m[a+l+1] == -1);
  if (m.find(a+l+2) != m.end()){
    assert(m[a+l+2] == 1);
    m.erase(a+l+2);
  } else {
    m[a+l+2] = -1;
  }
  m.erase(a+l+1);
  display();
  // Remove the 1 at a+l-k
  assert(m.find(a+l-k) == m.end());
  m[a+l-k] = -1;
  assert(m.find(a+l+1-k) == m.end());
  m[a+l+1-k] = 1;
  display();
}

void receive(int i){
  if (DEBUG)
    printf("Receiving %d\n", i);
  sc += ((long long) i) * i;
  map<int, int>::iterator ma = m.lower_bound(i);
  if (ma == m.end()){
    m[i] = 1;
    m[i+1] = -1;
  } else {
    if (DEBUG)
      printf("Found %d -> %d\n", ma->first, ma->second);
    if (ma->second == 1){
      if (ma->first == i){
	explode(i, 0, ((++ma) -> first) - (i + 1));
      } else {
	if (ma -> first == i+1){
	  m[i] = 1;
	  m.erase(i+1);
	}
	m[i] = 1;
	m[i+1] = -1;
      }
    } else {
      if (ma->first == i){
	++ma;
	if (ma->first == i + 1){
	  m.erase(i+1);
	} else {
	  m[i+1] = -1;
	}
	m.erase(i);
      } else {
	int num_after = (ma -> first) - i;
	--ma;
	int num_before = i - (ma -> first);
	explode(i, num_before, num_after - 1);
      }
    }
  }
}

long long val(int n){
  return ((((long long)n) * (n - 1) * (2 * n - 1))) / 6;
}

void get_rid_of(){
  for (map<int,int>::iterator w = m.begin(); w != m.end(); ++w){
    sc += val(w->first) * (w -> second);
  }
}

int main(){
  int num_cases; scanf("%d", &num_cases);
  for (int case_num = 1; case_num <= num_cases; ++case_num){
    int k; scanf("%d", &k);
    init();
    for (int y = 1; y <= k; ++y){
      int i, j; scanf("%d %d", &i, &j);
      for (int z = 1; z <= j; ++z)
	receive(i);
    }
    display();
    get_rid_of();
    sc = -sc;
    sc = sc >> 1;
    printf("Case #%d: ", case_num);
    cout << sc;
    printf("\n");
  }
}
