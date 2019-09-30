import collections
import math
n, m = [int(item) for item in input().split()]

def trial_division_sqrt(n):
    prime_count = collections.Counter()
    for i in range(2, int(math.sqrt(n)) + 2):
        while n % i == 0:
            n /= i
            prime_count[i] += 1
    if n > 1:
        prime_count[int(n)] += 1
    return prime_count

cnt = trial_division_sqrt(m)

ans = 1
for item in cnt:
  h = 1
  k_fact = 1
  for i in range(cnt[item]):
    h *= n + cnt[item] - 1 - i
    k_fact *= (i+1)
  ans *= h
  ans = ans // k_fact
  ans = ans % (1000000000 + 7)
print(ans)