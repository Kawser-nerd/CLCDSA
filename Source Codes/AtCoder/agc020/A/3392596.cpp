#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int main(int argc,char ** argv) {
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if(!(abs(a-b)%2)){
        printf("Alice");
    } else {
        printf("Borys");
    }
}