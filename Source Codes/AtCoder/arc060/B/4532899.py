import sys
sys.setrecursionlimit(10*5)

n = int(input())
s = int(input())

def f(b, n):
  if n < b:
    return n
  return n % b + f(b, n//b)

is_b = False
if n < s:
  print(-1)
elif n == s:
  print(n + 1)
else:
  b = 2
  is_b = False
  while b * b <= n:
    if s == f(b, n):
      is_b = True
      break
    b += 1
  if is_b:
    print(b)
  else:
    p = 1
    ans = -1
    while p * p <= n:
      if (n - s) % p != 0:
        p += 1
        continue
      else:
        b = (n-s) // p + 1
        if s == f(b, n):
          ans = min(b, ans) if ans != -1 else b
      p += 1
    print(ans)