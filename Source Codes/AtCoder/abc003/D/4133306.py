import sys
from math import factorial as fact

def nCr(n, r):
  if r > n:
    return 0
  else:
    return fact(n) // (fact(n - r) * fact(r))


def cal(n, d, l):
  if (n <= 0) or (n - d <= 0):
    return 0
  return nCr(n, d) * nCr(n-d, l)

def get_num_inner(x, y, d, l):
  all_ = cal(x*y, d, l)
  ng = cal((x-1)*y, d, l) * 2 + cal(x*(y-1), d, l) * 2\
       - cal((x-2)*y, d, l) - cal((x-1)*(y-1), d, l) * 4 - cal(x*(y-2), d, l)\
       + cal((x-2)*(y-1), d, l) * 2 + cal((x-1)*(y-2), d, l) * 2\
       - cal((x-2)*(y-2), d, l)
  return all_ - ng


def main():
  input = sys.stdin.readline
  r, c = map(int, input().split())
  x, y = map(int, input().split())
  d, l = map(int, input().split())
  o = (r - x + 1) * (c - y + 1)
  if (d + l) == (x * y):
    n = x * y
    i = nCr(n, d)
  else:
    i = get_num_inner(x, y, d, l)
  print((o * i) % 1000000007)


if __name__ == '__main__':
  main()