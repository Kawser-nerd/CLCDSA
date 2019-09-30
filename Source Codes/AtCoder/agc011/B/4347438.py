from itertools import accumulate
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
A = sorted(A)
a_acc = list(accumulate(A))

ans = N

seq = 1
for i in range(N-1):
    if a_acc[i]*2 >= A[i+1]:
        seq += 1
    else:
        ans -= seq
        seq = 1
print(ans)