N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
pos = "POSSIBLE"
imp = "IMPOSSIBLE"

if max(A) < K:
  print(imp)
  exit()

for i in range(1, N):
  a = A[i - 1]
  b = A[i]
  while a != b:
    if a < b:
      b -= (b // a) * a
      if b == 0:
        b = a
    else:
      a -= (a // b) * b
      if a == 0:
        a = b
  A[i - 1] = a
  A[i] = b

if K % A[-1] == 0:
  print(pos)
else:
  print(imp)