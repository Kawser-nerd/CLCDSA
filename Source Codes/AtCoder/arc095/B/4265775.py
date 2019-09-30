import bisect
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

A = sorted(A)

ma = A[-1]
A = A[:-1]
mi = -1
mid = ma/2

mid_ind = bisect.bisect_left(A, mid)
l = n-1
if mid_ind >= l:
    mi = A[-1]
elif mid_ind <= 0:
    mi = A[0]
else:
    if abs(A[mid_ind]-mid) > abs(A[mid_ind-1]-mid):
        mi = A[mid_ind-1]
    else:
        mi = A[mid_ind]
print(ma, mi)