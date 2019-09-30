import bisect

N = int(input())
A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]
C = [int(_) for _ in input().split()]

A = sorted(A)
C = sorted(C)
ans = 0

for i in B:
    ans += (bisect.bisect_left(A, i)) * (N - bisect.bisect_right(C, i))

print(ans)