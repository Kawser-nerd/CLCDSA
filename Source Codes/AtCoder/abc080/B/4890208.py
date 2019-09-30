N = int(input())

def f(N):
  s = 0
  while N > 0:
    s += N%10
    N //= 10
  return s

print('Yes' if N%f(N) == 0 else 'No')