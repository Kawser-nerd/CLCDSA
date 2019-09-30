// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/bron_kerbosch_all_cliques.hpp>
using namespace std; // using???????
const std::string name = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    int n,m;
    cin>>n>>m;
    std::vector<pair<int, int> > edge_list = {};
    for(int i =0;i<m;i++){
    int a,b;
    cin>>a>>b;
    edge_list.push_back({a,b});
    }
    
    
    
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
				boost::no_property,
				boost::no_property,
				boost::no_property> Graph;
  Graph graph(edge_list.begin(), edge_list.end(), n); // ???????????????????????, ??, vertex???
    if(n==0){
        cout<<0<<endl;
    }
    else if(m==0){
         cout<<1<<endl;
    }else{
  std::cout<<boost::bron_kerbosch_clique_number(graph)<<std::endl;
    }
 // boost::print_graph(graph, name.c_str());
  //???????????1???????????????
/*
  std::cout<<boost::bron_kerbosch_clique_number(graph)<<std::endl;
  std::cout << "Hello, Wandbox!" << std::endl;
*/
 
    
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://msdn.microsoft.com/library/3bstk3k5.aspx
//   http://www.cplusplus.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   http://www.boost.org/doc/