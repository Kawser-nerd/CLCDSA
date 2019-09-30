#include <cstdio>
using namespace std;
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d%d", &x, &y);
int main() {
  scii(A,B)sci(C)
  printf("%d\n",A*B*2+B*C*2+C*A*2);
}