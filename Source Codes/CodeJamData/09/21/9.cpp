#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<sstream>
using namespace std;

struct node
{
  string feat;
  double weight;
  vector<node> child;
};

double todbl(const string& s)
{ istringstream is(s);
  double rv;
  is>>rv;
  return rv;
}
string parses;
int parsest;
node parse()
{ parsest=parses.find('(',parsest);
  int i=parses.find_first_not_of(" \t\n",parsest+1);
  int j=parses.find_first_of(" \t\n)",i);
  node rv;
  rv.weight=todbl(parses.substr(i,j-i));
  i=parses.find_first_not_of(" \t\n",j);
  if(parses[i]!=')')
  { j=parses.find_first_of(" \t\n(",i);
    rv.feat=parses.substr(i,j-i);
    parsest=j;
    rv.child.push_back(parse());
    rv.child.push_back(parse());
    parsest=parses.find(')',parsest)+1;
  }else parsest=i+1;
  return rv;
}

double cuteness(const set<string>& feature,const node& tree)
{
  double p=tree.weight;
  const node* cur=&tree;
  while(!cur->feat.empty())
  { if(feature.count(cur->feat)) cur=&cur->child[0];
    else cur=&cur->child[1];
    p*=cur->weight;
  }
  return p;
}

int main()
{
  int ci,cn;
  cin>>cn;
  for(ci=1;ci<=cn;++ci)
  { int lines,i,n;
    string line;
    parses.clear(); parsest=0;
    cin>>lines; cin.ignore();
    for(i=0;i<lines;++i) 
    { getline(cin,line);
      parses+=line+'\n';
    }
    node tree=parse();
    cin>>n;
    cout<<"Case #"<<ci<<":\n";
    for(i=0;i<n;++i)
    { string ani,feat;
      set<string> feats;
      int fc,j;
      cin>>ani>>fc;
      for(j=0;j<fc;++j)
      { cin>>feat;
        feats.insert(feat);
      }
      cout.precision(8);
      cout<<fixed<<cuteness(feats,tree)<<endl;
    }
  }
}
