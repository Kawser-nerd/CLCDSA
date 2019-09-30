# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

seq = 0
ans = 0
for i in range(1, N+1):
    if A[i-1] == i:
        seq += 1
    else:
        ans += (seq+1)//2
        seq = 0
ans += (seq+1)//2
print(ans)