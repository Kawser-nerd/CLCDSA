#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define NIL -1
#define N_MAX 100000
#define M_MAX 100000

struct Node{
    int value;
    int parent;
};

struct Node node[N_MAX];

void init(int n){
    for(int i = 0; i <= n; i++){
        node[i].value = i;
        node[i].parent = NIL;
    }
}

int find(int x){
    struct Node target_node = node[x];
    vector<int> v;
    while(target_node.parent != NIL){
        v.push_back(target_node.value);
        target_node = node[target_node.parent];
    }

    for(int i = 0; i < v.size(); i++){
        node[v[i]].parent = target_node.value;
    }

    return target_node.value;
}

void unite(int x, int y){
    if(find(x) != find(y)){
        node[find(x)].parent = y;
    }
}

bool same(int x, int y){
    if(find(x) == find(y)){
        return true;
    }else{
        return false;
    }
}


int main(void){
    int N, M;
    int p[N_MAX];

    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < N; i++){
        scanf("%d", &p[i]);
    }

    init(N);

    for(int i = 0; i < M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        unite(x, y);
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        if(same(i + 1, p[i])){
            count += 1;
        }
    }

    printf("%d\n", count);

}