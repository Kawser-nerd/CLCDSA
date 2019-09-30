#include<iostream>
using namespace std;
int main()
{
  string id;
  int year;

  cin >> id;

  for(int i = 0; i < id.size(); i++) {
    if( isdigit(id[i]) ){
      if( i == id.size() - 1 || !isdigit(id[i+1]) ) {
        cout << (int)(id[i] - '0');
        break;
      }
      else{
        cout << stoi( id.substr(i,2) );
        break;
      }
    }
  }
    return 0;
}