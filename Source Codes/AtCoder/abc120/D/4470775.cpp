#include <iostream>
#include <stdint.h>
#include <vector>
#include <limits.h>
#include <utility>
#include <memory>
#include <set>
#include <map>

using namespace std;

using Group = set<int>;

inline uint64_t calc_convenience(Group& group)
{
  uint64_t island_count = group.size();
  return island_count * (island_count-1) / 2;
}

int main()
{
  int N,M;
  cin >> N >> M;

  vector<pair<int,int>> bridges;
  
  for (int m=0; m<M; ++m) {
    int a,b;
    cin >> a >> b;
    bridges.push_back(pair<int,int>(a,b));
  }

  map<int,shared_ptr<Group>> island2group;
  set<shared_ptr<Group>> groups;

  for (int n=0; n<N; ++n) {
    Group new_group = {n+1};
    auto ptr_new_group = make_shared<Group>(new_group);
    island2group[n+1] = ptr_new_group;
    groups.insert(ptr_new_group);
  }

  vector<uint64_t> conveniences = {0};

  for (int m=M-1; m>=0; m--) {
    auto bridge = bridges[m];
    int a = bridge.first, b = bridge.second;
    auto group_a = island2group[a];
    auto group_b = island2group[b];
    uint64_t convenience_prev = calc_convenience(*group_a) + calc_convenience(*group_b);
    if (group_a != group_b) {
      if (group_b->size() > group_a->size())
	swap(group_a,group_b);

      for (int island_b : *group_b) {
	group_a->insert(island_b);
	island2group[island_b] = group_a;
      }
      groups.erase(group_b);
      uint64_t convenience_now = calc_convenience(*group_a);
      conveniences.push_back(conveniences.back()+convenience_now-convenience_prev);
    } else {
      conveniences.push_back(conveniences.back());
    }
  }

  uint64_t final_convenience = conveniences.back();
  for (auto itr = conveniences.rbegin()+1; itr != conveniences.rend(); ++itr) {
    cout << final_convenience - *itr << endl;
  }
  
  return 0;
}