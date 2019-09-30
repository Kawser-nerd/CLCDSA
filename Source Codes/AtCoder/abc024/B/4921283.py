N, T = map(int, input().split())
A = [int(input()) for i in range(N)]

total = 0
pre = 0
for i in range(N):
  total += T
  if pre > A[i]:
    total -= pre - A[i]
  pre = A[i] + T

print(total)