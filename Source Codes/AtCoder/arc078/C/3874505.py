def solve(SECRET = None):
  num_asks = 0
  def ask(n):
    n = int(n)
    nonlocal num_asks
    num_asks += 1
    assert 1 <= n <= int(1e18)
    if SECRET:
      return (n <= SECRET) == (str(n) <= str(SECRET))
    else:
      print("?", n)
      return input() == 'Y'

  if ask(100000000000):
    for k in range(1,19):
      if ask("9"*k):
        return 10**(k-1), num_asks
  else:
    for k in range(1,10):
      if not ask(10**k):
        # len == k
        low = 10**(k-1)
        high = (10**k) - 1
        ret = -1
        while low <= high:
          mid = (low + high) // 2
          if ask(str(mid) + "9"*k):
            ret = mid
            high = mid - 1
          else:
            low = mid + 1
        return ret, num_asks

  return -1, num_asks

ans, _ = solve()
print("!", ans)
exit(0)

#for SECRET in range(1,1000):
import random
num_iter = 0
while True:
  num_iter += 1
  secret_len = random.randint(1, 9)
  SECRET = random.randrange(10**(secret_len-1),10**secret_len)
  ans, num_asks = solve(SECRET)
  assert num_asks <= 64
  if SECRET != ans or num_asks > 64:
    print(num_iter, "..", SECRET, ":", ans, num_asks)
    break
  if num_iter % 1000 == 0:
    print(num_iter)