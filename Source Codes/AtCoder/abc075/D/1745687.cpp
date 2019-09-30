#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int main()
{
  int n, required;
  cin >> n >> required;

  vector<pii> points(n);

  for (int i = 0; i < n; ++i)
    cin >> points[i].first >> points[i].second;

  vector<pii> ypoints(points);

  sort(points.begin(), points.end());
  sort(ypoints.begin(), ypoints.end(), [] (const pii a, const pii b) {
      return a.second < b.second;
      });

  /*
   *  --k--
   *  |   |
   *  i   j
   *  |   |
   *  --l--
   */

  auto contained = [&points, &ypoints](int i, int j, int k, int l)-> int {
    int contained = 0;

    for (auto point : points)
      if ((point.first  >= points[i].first)  &&
          (point.first  <= points[j].first)  &&
          (point.second >= ypoints[k].second) &&
          (point.second <= ypoints[l].second))
        contained++;

    return contained;
  };

  auto area = [&points, &ypoints](int i, int j, int k, int l)-> long long {
    return (long long)(points[j].first - points[i].first) *
                      (ypoints[l].second - ypoints[k].second);
  };

  long long best = area(0, n-1, 0, n-1);

  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      for (int k = 0; k < n; ++k)
        for (int l = k+1; l < n; ++l)
          if (contained(i, j, k, l) >= required)
            best = min(best, area(i, j, k, l));

  cout << best << '\n';
}