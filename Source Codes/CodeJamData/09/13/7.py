filename = 'C-large'
#filename = 'test'

f = open(filename + '.in', 'r')
lines = f.readlines()
f.close()

MAX = 41
FACT = [0.0] * MAX
def fact(n):
  if FACT[n] != 0:
    return FACT[n]
  tot = 1.0
  for x in xrange(1, n + 1):
    tot *= x
  FACT[n] = tot
  return tot

def choose(N, k):
  if k > N:
    return 0.0
  return fact(N) / fact(k) / fact(N - k)

print choose(5, 0), choose(5, 1), choose(5, 5), choose(5, 7)

CACHE = {}
def get_exp_num(C, N, S):
  if S in CACHE:
    return CACHE[S]
  if S >= C:
    return 0.0
  tot_num = choose(C, N)
  self_fact = choose(C - S, 0) * choose(S, N) / tot_num
  ans = 0.0
  ans += 1.0 * self_fact
  for k in xrange(1, N + 1):
    prob = choose(C - S, k) * choose(S, N - k) / tot_num
    ans += prob * (1.0 + get_exp_num(C, N, S + k))
  ans = ans / (1.0 - self_fact) 
  CACHE[S] = ans
  return ans

out = open(filename + '.out', 'w')

T = int(lines[0].strip())
case = 1
for line in lines[1:]:
  C, N = [int(x) for x in line.strip().split(' ')]  
  CACHE = {}
  ans = get_exp_num(C, N, 0)
  print 'Case #%d: %0.6f' % (case, ans)
  out.write('Case #%d: %0.6f\n' % (case, ans))
  case += 1

out.close()
