N, M, X = list(map(int, input().split()))
A = list(map(int, input().split()))

l = 0
r = 0

for i in A:
  if i < X:
    l += 1
  else:
    r += 1

print(min(l, r))