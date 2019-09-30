from collections import Counter
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


R, C, K = map(int, input().split())

N = int(input())
X = [0]*R
Y = [0]*C
pos = []
for _ in range(N):
    a, b = map(lambda x: int(x)-1, input().split())
    X[a] += 1
    Y[b] += 1
    pos.append([a, b])

Cx = Counter(X)
Cy = Counter(Y)

ans = 0
for i in range(0, K+1):
    ans += Cx[i]*Cy[K-i]

for x, y in pos:
    if X[x]+Y[y] == K:
        ans -= 1
    elif X[x]+Y[y] == K+1:
        ans += 1
print(ans)