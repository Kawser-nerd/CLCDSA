# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

for i in range(1, N+1):
    A[i-1] -= i

# print(A)

ans = 0
if all(a != 0 for a in A):
    ans = 0
else:
    seq = 0
    for i in range(N):
        if A[i] == 0:
            seq += 1
        else:
            ans += (seq+1)//2
            seq = 0
    ans += (seq+1)//2
print(ans)