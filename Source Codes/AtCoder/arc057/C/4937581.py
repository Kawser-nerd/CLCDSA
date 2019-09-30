import itertools
import math
from collections import defaultdict

def input_ints():
    return list(map(int, input().split()))

def solve():
    x = int(input())
    a = x ** 2
    b = (x + 1) ** 2
    for i in range(1010):
        d = 10 ** (2 * i)
        c = (a + d - 1) // d
        if a <= c * (10 ** (2 * i)) < b:
            ans = c
    print(ans)

if __name__ == '__main__':
    solve()