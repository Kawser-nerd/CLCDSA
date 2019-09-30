# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N, K = map(int, input().split())
t = [int(input()) for _ in range(N)]
s = sum(t[:3])

if s < K:
    print(3)
    exit()
else:
    for i in range(3, N):
        s = s+t[i]-t[i-3]
        if s < K:
            print(i+1)
            exit()
print(-1)