N = int(input())
A = {}
for _ in range(N):
  a = int(input())
  if a in A:
    A[a] += 1
    A[a] %= 2
  else:
    A[a] = 1
ans=0
for key in A.keys():
  ans += A[key]
print(ans)