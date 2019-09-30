def ints():
  return map(int, raw_input().split())

num_cases, = ints()

M = 1000000
primes = [2, 3]
for q in xrange(5, M, 2):
  is_prime = True
  for p in primes:
    if p * p > q:
      break
    if q % p == 0:
      is_prime = False
      break
  if is_prime:
    primes.append(q)

for case_num in xrange(1, num_cases + 1):
  n = int(raw_input())
  res = 1
  for  p in primes:
    k = 0
    x = 1
    while x <= n:
      k += 1
      x *= p
    res += max(0, k - 2)
  if n == 1:
    res = 0

  print "Case #%d: %d" % (case_num, res)
