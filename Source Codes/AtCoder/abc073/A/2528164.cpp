#include <cstdio>
using namespace std;

int main() {
    char a, b;
    scanf("%c%c", &a, &b);
    if (a == '9' or b == '9') printf("Yes\n");
    else printf("No\n");
    return 0;
}