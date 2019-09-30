# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
P = list(map(int, input().split()))

A = [N*i+1 for i in range(1, N+1)]
B = list(reversed(A))

for i, p in enumerate(P):
    A[p-1] -= N-i
print(*A)
print(*B)