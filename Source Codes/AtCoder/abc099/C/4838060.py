from collections import defaultdict
from string import ascii_uppercase
import sys, bisect
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N = read_int()[0]

items = [1]
Nd6 = 0
while True:
    if N // (6**(Nd6 + 1)) > 0:
        Nd6 += 1
        items.append(6 ** Nd6)
    else: break

Nd9 = 0
while True:
    if N // (9 ** (Nd9 + 1)) > 0:
        Nd9 += 1
        items.append(9 ** Nd9)
    else: break

items.sort()

dp = [0 for _ in range(N + 1)]
def solve():
    for i in range(N):
        for itm in items:
            if i + itm < N + 1:
                if dp[i + itm] == 0:
                    dp[i + itm] =dp[i] + 1
                else:
                    dp[i + itm] = min(dp[i + itm], dp[i] + 1)

    return dp[N]
  

if __name__ == "__main__":
    print(solve())