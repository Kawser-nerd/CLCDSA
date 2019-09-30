N, T = map(int, input().split())

amount = 0
pre = int(input())
for _ in range(N-1):
  a = int(input())
  if (a-pre) < T:
    amount += (a-pre)
  else:
    amount += T
  pre = a
amount += T

print(amount)