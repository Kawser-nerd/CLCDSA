#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  map <int, int> data;
  vector <int> result(N * N, -1);

  int i, place;
  for (i = 0; i < N; i++) {
    cin >> place;
    data[place] = i + 1;
  }

  int finished;

  map <int, int>::reverse_iterator mri;
  finished = N * N;
  for (mri = data.rbegin(); mri != data.rend(); mri++) {
    const int number = mri->second;
    int leftnum = N - number;
    while (leftnum > 0) {
      finished--;
      if (finished <= mri->first - 1) {
        cout << "No" << endl;
        return 0;
      }
      if(result[finished] < 0) {
        result[finished] = number;
        leftnum--;
      }
    }
    result[mri->first - 1] = number;
  }

  map <int, int>::iterator mit;
  finished = -1;
  for (mit = data.begin(); mit != data.end(); mit++) {
    const int number = mit->second;
    int leftnum = number - 1;
    while (leftnum > 0) {
      finished++;
      if (finished >= mit->first - 1) {
        cout << "No" <<endl;
        return 0;
      }
      if (result[finished] < 0) {
        result[finished] = number;
        leftnum--;
      }
    }
  }

  cout << "Yes" << endl;
  for (i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  } cout << endl;

  return 0;
}