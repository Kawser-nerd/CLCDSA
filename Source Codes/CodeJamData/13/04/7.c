#include <cstdio>
#include <vector>

using namespace std;

struct Chest {
  int id, need;
  vector<int> item;
};


bool solved;

void solve(int * have, vector<Chest> chest, vector<int> path) {
  if (solved) return;
  if (!chest.size()) {
    for (int i = 0; i < path.size(); i++)
      printf("%d%s", path[i], i == path.size() - 1 ? "\n" : " ");
    solved = true;
    return;
  }
  for (int i = 0; i < chest.size(); i++)
    if (have[chest[i].need] > 0) {
      have[chest[i].need]--;
      for (int j = 0; j < chest[i].item.size(); j++)
        have[chest[i].item[j]]++;
      path.push_back(chest[i].id);
      vector<Chest> newChest = chest;
      newChest.erase(newChest.begin() + i);

      solve(have, newChest, path);
      
      have[chest[i].need]++;
      for (int j = 0; j < chest[i].item.size(); j++)
        have[chest[i].item[j]]--;
      path.pop_back();
    }
}
int main() {
  int C = 1, T;
  scanf("%d", &T);
  while (T--) {
    int k, n;
    scanf("%d%d", &k, &n);
    int have[201] = {}, all[201] = {};
    for (int i = 0, id; i < k; i++) {
      scanf("%d", &id);
      have[id]++;
      all[id]++;
    }
    vector<Chest> chest;
    for (int i = 0, t, k; i < n; i++) {
      Chest tempChest;
      scanf("%d%d", &t, &k);
      tempChest.id = i + 1;
      tempChest.need = t;
      all[t]--;
      while (k--) {
        scanf("%d", &t);
        tempChest.item.push_back(t);
        all[t]++;
      }
      chest.push_back(tempChest);
    }
    printf("Case #%d: ", C++);
    vector<int> path;
    solved = false;
    bool run = true;
    for (int i = 0; i < 201; i++)
      if (all[i] < 0) run = false;
    if (run) {
      solve(have, chest, path);
    }
    if (!solved) puts("IMPOSSIBLE");
  }
  return 0;
}
