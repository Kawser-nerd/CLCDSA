n = int(input())
A = [2 ** i for i in range(1, 7)]
ans = 1
for a in A:
  if (n < a):
    break
  ans = a
print(ans)