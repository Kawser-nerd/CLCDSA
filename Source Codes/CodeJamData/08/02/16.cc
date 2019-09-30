#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int readTime() {
  int h, m;
  cin >> h; cin.ignore(); cin >> m;
  return 60*h + m;
  }

int nextT(vector<int>::iterator pLeave[2], vector<int>::iterator pTurn[2]) {
  int t = 1000000;
  for (int i = 0; i < 2; ++i) {
    if (*pLeave[i] < t) t = *pLeave[i];
    if (*pTurn[i] < t) t = *pTurn[i];
    }
  return t;
  }

int main() {
  int N; cin >> N;
  for (int c = 1; c <= N; ++c) {
    int T, NA, NB; cin >> T >> NA >> NB;
    vector<int> trainLeaves[2], trainTurns[2];
    for (int i = 0; i < NA; ++i) {
      trainLeaves[0].push_back(readTime());
      trainTurns[1].push_back(readTime()+T);
      }
    for (int i = 0; i < NB; ++i) {
      trainLeaves[1].push_back(readTime());
      trainTurns[0].push_back(readTime()+T);
      }
    int startTrains[2] = {0}, curTrains[2] = {0};
    vector<int>::iterator pLeave[2], pTurn[2];
    for (int i = 0; i < 2; ++i) {
      sort(trainLeaves[i].begin(), trainLeaves[i].end());
      sort(trainTurns[i].begin(), trainTurns[i].end());
      trainLeaves[i].push_back(1000000);
      trainTurns[i].push_back(1000000);
      pLeave[i] = trainLeaves[i].begin();
      pTurn[i] = trainTurns[i].begin();
      }
    for (int curT = nextT(pLeave, pTurn); curT < 1000000; curT = nextT(pLeave, pTurn))
      for (int i = 0; i < 2; ++i) {
        while (*pLeave[i] == curT) {
          --curTrains[i]; ++pLeave[i];
          }
        while (*pTurn[i] == curT) {
          ++curTrains[i]; ++pTurn[i];
          }
        if (curTrains[i] < 0) {
          startTrains[i] -= curTrains[i];
          curTrains[i] = 0;
          }
        }
    cout << "Case #" << c << ": " << startTrains[0] << " " << startTrains[1] << "\n";
    }
  }