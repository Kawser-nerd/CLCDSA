from sys import stdin

T = int(stdin.readline())

def gen(x):
  t = bin(x)[2:]
  t = '0' * (32 - len(t)) + t
  for i in range(32):
    if t[i] == '1':
      yield t[:i] + '0' + 'x'*(32 - i - 1)

def solve(a, b, c):
  ret = 1
  for i in range(32):
    if c[i] == 'x':
      if a[i] == 'x':
        ret *= 2
      if b[i] == 'x':
        ret *= 2
    else:
      tmp = 0
      for aa in ('01' if a[i] == 'x' else a[i]):
        for bb in ('01' if b[i] == 'x' else b[i]):
          if (int(aa) & int(bb)) == int(c[i]):
            tmp += 1
      ret *= tmp
  return ret

for no in range(1, T+1):
  A, B, C = map(int, stdin.readline().split())
  ans = 0
  for a in gen(A):
    for b in gen(B):
      for c in gen(C):
        ans += solve(a, b, c)
  print "Case #{}: {}".format(no, ans)
