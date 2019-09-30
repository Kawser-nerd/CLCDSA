# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, A, B = map(int, input().split())

L = [int(input()) for _ in range(N)]

me = sum(L)/N
diff = max(L)-min(L)

if diff == 0:
    print(-1)
else:
    P = B/(diff)
    Q = A - P*me
    print(P, Q)