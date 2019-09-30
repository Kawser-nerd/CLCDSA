# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int, input().split())

l = [[v, i] for i, v in enumerate(reversed(range(N)))]
for _ in range(M):
    N += 1
    n = int(input())-1
    l[n][0] = N

l = sorted(l, key=lambda x: x[0], reverse=True)
for v, i in l:
    print(i+1)