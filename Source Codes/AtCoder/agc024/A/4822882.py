import sys
input = sys.stdin.readline

A, B, C, K = map(int, input().split())
ans = (-1)**K * (A-B)

print(ans if abs(ans) <= 10**18 else 'Unfair')