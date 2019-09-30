def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

n = int(input())
if n >= 15002:
  if n % 2 == 0:
    a = [i*2 for i in range(1,15001)] + [i*6 + 3 for i in range(n - 15000)]
  else:
    a = [i*2 for i in range(1,15000)] + [i*6 + 3 for i in range(n - 14999)]
  print(*a)
elif n == 3:
  print(*[2,5,63])
else:
  b = prime_factors((n-1)*(n-2))
  b.sort()
  c = 0
  for i in b:
    if i >= 3:
      c = i
      break
  d = [i*2 for i in range(1,n-1)] + [c,c*3]
  print(*d)