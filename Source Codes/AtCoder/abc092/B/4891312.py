import math

N = int(input())
D, X = list(map(int, input().split()))
A = [int(input()) for _ in range(N)]

Ans = X

for i in A:
  Ans += math.ceil(D / i)

print(Ans)