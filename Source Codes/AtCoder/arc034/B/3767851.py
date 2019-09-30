N = int(input())
MAX = 9*17

def f(x):
  if x <= 0:
    return -1000
  ret = 0
  while x:
    ret += x%10
    x //= 10
  return ret

ans = []
for i in range(1, MAX+1):
  x = N-i
  if f(x) + x == N:
    ans.append(x)
ans.sort()
print(len(ans))
[print(x) for x in ans]