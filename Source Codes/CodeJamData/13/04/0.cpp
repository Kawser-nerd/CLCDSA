#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
using namespace std;

const int M = 403;


int requires[M];
map<int, int> contains[M];
set<int> links[M];

vector<int> result;

typedef set<int>::iterator SETIT;
typedef map<int, int>::iterator MAPIT;

void insertMap(map<int, int> & b, map<int, int> & a) {
    for (MAPIT it = a.begin(); it != a.end(); ++it) {
        if (b.find(it->first) == b.end()) {
            b[it->first] = it->second;
        } else {
            b[it->first] += it->second;
        }
    }
}

map<int, int> read(int k) {
    map<int, int> result;
    while(k--) {
        int l; scanf("%d", &l);
        if (result.find(l) == result.end()) {
            result[l] = 1;
        } else {
            ++result[l];
        }
    }
    return result;
}

bool enoughKeys(set<int> & rest, map<int, int> keys) {
    for (SETIT it = rest.begin(); it != rest.end(); ++it) {
        insertMap(keys, contains[*it]);
    }
    for (SETIT it = rest.begin(); it != rest.end(); ++it) {
        if (keys.find(requires[*it]) == keys.end()) {
            return false;
        }
        if ((--keys[requires[*it]]) == -1) {
            return false;
        }
    }
    return true;
}

bool allReachable(set<int> rest, map<int, int> & keysM) {
    set<int> keys;
    vector<int> keysQ;
    for (MAPIT it = keysM.begin(); it != keysM.end(); ++it) {
        if (it->second > 0) {
            keysQ.push_back(it->first);
            keys.insert(keysQ.back());
        }
    }
    for (int i=0; i<keysQ.size(); ++i) {
        for (SETIT it = links[keysQ[i]].begin(); it != links[keysQ[i]].end(); ++it) {
            if (rest.find(*it) == rest.end()) {
                continue;
            }
            rest.erase(*it);
            for (MAPIT it2 = contains[*it].begin(); it2 != contains[*it].end(); ++it2) {
                if (keys.find(it2->first) == keys.end()) {
                    keysQ.push_back(it2->first);
                    keys.insert(it2->first);
                }
            }
        }
    }
    return rest.empty();
}

bool solvable(set<int> & rest, map<int, int> & keys) {
/*
    printf("===\n");
    for (SETIT it = rest.begin(); it != rest.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    for (MAPIT it = keys.begin(); it != keys.end(); ++it) {
        printf("%d %d\n", it->first, it->second);
    }
*/
    return allReachable(rest, keys) && enoughKeys(rest, keys);
}

void fill(set<int> & rest, map<int, int> & keys) {
    while (!rest.empty()) {
        bool ok = false;
        for (SETIT it = rest.begin(); it != rest.end(); ++it) {
            int i = *it;
            
            if (keys.find(requires[i]) == keys.end()) continue;
            if (keys[requires[i]] == 0) continue;

            set<int> rrest(rest);
            rrest.erase(i);
            
            map<int, int> kkeys(keys);
            if ((--kkeys[requires[i]]) == 0) {
                kkeys.erase(requires[i]);
            }
            insertMap(kkeys, contains[i]);

            links[requires[i]].erase(i);

            if (solvable(rrest, kkeys)) {
//                printf("Gites: %d\n", i);
                rest = rrest;
                keys = kkeys;
                ok = true;
                result.push_back(i);
                break;
            }
            
            links[requires[i]].insert(i);
        }
        if (!ok) {
            printf("ERROR\n");
            exit(1);
        }
    }
}

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);
    map<int, int> keys;
    set<int> rest;
    
    int k, n; scanf("%d %d", &k, &n);
    keys = read(k);
    for (int i=0; i<n; ++i) {
        scanf("%d", &requires[i]);
        scanf("%d", &k);
        contains[i] = read(k);
    }
    
    rest.clear();
    for (int i=0; i<M; ++i) {
        links[i].clear();
    }
    for (int i=0; i<n; ++i) {
        rest.insert(i);
        links[requires[i]].insert(i);
    }

    if (!solvable(rest, keys)) {
        printf("IMPOSSIBLE\n");
        return;
    }

    result.clear();

    fill(rest, keys);
    for (int i=0; i<result.size(); ++i) {
        printf("%d ", result[i]+1);
    }
    printf("\n");
    return;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        make();
    }
    return 0;
}
