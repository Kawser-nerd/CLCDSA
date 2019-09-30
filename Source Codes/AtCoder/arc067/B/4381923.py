# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, A, B = map(int, input().split())

ans = 0
L = list(map(int, input().split()))

diff = [0]*N
for i in range(N):
    diff[i] = L[i]-L[i-1]

for i in range(1, N):
    if diff[i]*A >= B:
        ans += B
    else:
        ans += diff[i]*A
print(ans)