from functools import reduce


def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

  
N, K = map(int, input().split())
lst_A = list(map(int, input().split()))
max_A = max(lst_A)
gcd_A = reduce(gcd, lst_A)

ans = "IMPOSSIBLE"
if K%gcd_A==0 and K<=max_A:
    ans = "POSSIBLE"

print(ans)