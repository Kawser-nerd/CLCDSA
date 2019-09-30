n = int(input())
k = 0
ans = []

def prime(p):
  j = 2
  while j * j <= p:
    if p % j == 0:
      return False
    j += 1
  return True

for i in range(6, 55556, 5):
  if k == n:
    break
  if prime(i):
    ans.append(i)
    k += 1

print(*ans)