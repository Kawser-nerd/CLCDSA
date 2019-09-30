def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

import sys
input = sys.stdin.readline
N = int(input())
if N == 1:
    print(input())
else:
    T = [int(input()) for _ in range(N)]
    ans = lcm(T[0], T[1])
    for i in range(2, N):
        ans = lcm(ans, T[i])
    print(ans)