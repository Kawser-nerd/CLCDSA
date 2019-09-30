#!/usr/bin/python3

def solve():
    d, n = map(int, input().split())
    ans = 10 ** 100
    for i in range(n):
        k, s = map(int, input().split())
        ans = min(ans, d * s / (d - k))
    return ans

t = int(input())
for i in range(t):
    print("Case #%d: %.20f" % (i + 1, solve()))
    
