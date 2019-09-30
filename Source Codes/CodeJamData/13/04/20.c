#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <queue>
using namespace std;
int debug = 0;

int K, N; 
int has_key[201];
int chest_key_type[201];
int chest_key_num[201];
int chest_has_key[201][400];
int chest_to_solve[201];
int remain_gain[201];
int remain_cost[201];
int chest_key_sort[201];
char chest_id[201][4000];
        
vector<int> result;

// take all the has_key + chest_to_solve->has_key
int predict_possibility() {
    for (int i = 1; i <= 200; i++) {
        if (remain_cost[i] && (remain_cost[i] > remain_gain[i] + has_key[i])) {
            return 0;
        }
    }
    
    for (int i = 1; i <= N;  i++) {
         if (chest_to_solve[i] && (has_key[chest_key_type[i]] == 0)) {
             int n = remain_gain[chest_key_type[i]];
             for (int j = 0; j < chest_key_num[i]; j++) {
                 if (chest_has_key[i][j] == chest_key_type[i]) {
                     n--;
                 }
             }
             if (n == 0) return 0;
         }
    }
    return 1;
}

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

int solve_recur() {
   if (debug) {
       cout << "recur enter" << endl; 
       copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
       cout << endl;
   }
   if ((int)result.size() == N) {
       for (int i = 0; i < N; i++) {
           cout << result[i]; 
           if (i != N-1) cout << " "; 
       }
       cout << endl;
       return 1;
   }
   if (predict_possibility() == 0) return 0;
            
   set<char*, ltstr> visit;  
   for (int i = 1; i <= N; i++) {
        if (chest_to_solve[i] == 0) continue;

        if (visit.find(chest_id[i]) != visit.end()) continue;
        visit.insert(chest_id[i]);

        if (has_key[chest_key_type[i]] > 0) {
            // commit it    
            has_key[chest_key_type[i]]--;
            result.push_back(i); 
            chest_to_solve[i] = 0;
            remain_cost[chest_key_type[i]]--;
            for (int j = 0; j < chest_key_num[i]; j++) {
                 has_key[chest_has_key[i][j]]++;
                 remain_gain[chest_has_key[i][j]]--;
            }
            

            // recursive call 
            int ret = solve_recur();
            if (ret) return 1;
            
            // un-commit it 
            has_key[chest_key_type[i]]++;
            result.pop_back();
            chest_to_solve[i] = 1;
            remain_cost[chest_key_type[i]]++;
            for (int j = 0; j < chest_key_num[i]; j++) {
                 has_key[chest_has_key[i][j]]--;
                 remain_gain[chest_has_key[i][j]]++;
            }
        }
   }
   return 0;
}

void get_result() {
    if (debug) {
        cout << endl << K << " " << N << endl; 
        cout << "key begins: " << endl; 
        for (int i = 1; i <= 200;  i++) {
            if (has_key[i] > 0) {
               cout << "type=" << i << ": " << has_key[i] << endl;
            }
        }
        cout << "chest:" << endl;
        for (int i = 1; i <= N; i++) {
            cout << "type=" << chest_key_type[i]; 
            cout << " keys: "; 
            for (int j = 0; j < chest_key_num[i]; j++) {
                cout << chest_has_key[i][j] << " "; 
            }
            cout << " keyid:" << chest_id[i] << endl;
        }
    }

    result.clear(); 
    int ret = solve_recur(); 
    if (ret == 0) cout << "IMPOSSIBLE" << endl;
}


int main() { 
    int T; 
    string str;
    cin >> T;
    getline(cin, str);

    for (int cnum = 1; cnum <= T; cnum++) {
        // initialize 
        for (int i = 1; i <= 200; i++) {
            has_key[i] = 0;
            remain_cost[i] = 0;
            remain_gain[i] = 0;
        }
        for (int i = 1; i <= 200;  i++) {
            chest_to_solve[i] = 0;
        }
        cin >> K >> N; 
        getline(cin, str);
        for (int i = 0; i < K; i++) {
            int key_type;
            cin >> key_type; 
            has_key[key_type]++;
        }
        getline(cin, str);
        for (int i = 1; i <= N; i++) {
            chest_to_solve[i] = 1;
            cin >> chest_key_type[i];
            cin >> chest_key_num[i];
            remain_cost[chest_key_type[i]]++;
            sprintf(chest_id[i], "%d", chest_key_type[i]);
            for (int k = 1; k <= 200;  k++) {
                chest_key_sort[k] = 0;
            }
            for (int j = 0; j < chest_key_num[i]; j++) {
                cin >> chest_has_key[i][j];
                remain_gain[chest_has_key[i][j]]++;
                chest_key_sort[chest_has_key[i][j]]++;
            }
            for (int k = 1; k <= 200;  k++) {
                if (chest_key_sort[k]) {
                    sprintf(chest_id[i], "%s_%d_%d", chest_id[i], k,
                            chest_key_sort[k]);
                }
            }
            getline(cin, str);
        }
        cout << "Case #" << cnum << ": ";
        get_result();
    }
} 
