import math

N = int(input())
A = [int(_) for _ in input().split()]
A = sorted(A)
List = []

if N % 2 == 0:
    for i in range(N):
        List.append(i//2 * 2 + 1)
else:
    for i in range(N):
        List.append(math.ceil(i/2) * 2)

if A != List:
    print(0)
else:
    print(2**(N//2) % (10**9+7))