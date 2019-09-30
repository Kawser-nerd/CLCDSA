#include <set>
#include <iostream>

using namespace std;

typedef set<string> Set;

int main(int argc, char** argv)
{
  int cases;
  cin >> cases;
  for (int c = 0; c<cases;c++)
  {

    int engins;
    cin >> engins;
    string t;
    getline(cin,t);//endl
    //we don't realy need these
    for (int i = engins; i-->0;)
    {
      getline(cin,t);
    }
    int queries;
    cin >> queries;
    getline(cin,t);//endl
    int switches = 0;
    Set exclude;
    for (; queries-->0;)
    {
      string q;
      getline(cin,q);
      if ((exclude.size()==engins-1) && exclude.find(q)==exclude.end())
      {
        //we have to switch
        exclude.clear();
        ++switches;
      }
      exclude.insert(q);
    }
    cout << "Case #" << (c+1) << ": " << switches << endl;
  }
}
