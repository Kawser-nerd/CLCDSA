#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector<int> numbers;

void read_happies()
{
  ifstream is("happies.txt");
  while ( is )
  {
    int x;
    is >> x;
    numbers.push_back(x);
  }
}

size_t smallest(string const &s)
{
  istringstream is(s);
  int m = 0;
  while ( is )
  {
    int x;
    is >> x;
    m |= (1<<(x - 2));
  }
  for ( size_t i=1; i<numbers.size(); ++i )
    if ( (numbers[i] & m) == m )
      return i + 1;
  return size_t(-1);
}


int main()
{
  read_happies();
  int T;
  cin >> T;
  string line;
  getline(cin, line);
  for ( int t=1; t<=T; ++t )
  {
    getline(cin, line);
    int x = smallest(line);
    cout << "Case #" << t << ": " << x << endl;
  }

  return 0;
}
