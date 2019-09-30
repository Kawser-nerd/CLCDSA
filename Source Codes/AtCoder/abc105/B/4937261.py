from collections import defaultdict
from string import ascii_uppercase
import sys, bisect, math
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N = read_int()[0]

l = [False for _ in range(N + 1)]
def solve():
    ans = 0
    l[0] = True
    for i in range(N + 1):
        if l[i] and i + 4 < N + 1:
            l[i + 4] = True
    for i in range(N + 1):
        if l[i] and i + 7 < N + 1:
            l[i + 7] = True
    return l[N]

if __name__ == "__main__":
    if solve():
        print("Yes")
    else:
        print("No")