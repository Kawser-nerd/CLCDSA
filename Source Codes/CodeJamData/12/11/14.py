def solve():
  a, b = raw_input().split()
  a = int(a)
  b = int(b)
  p = map(float, raw_input().split())
  answer = 2 + b
  prod = 1.0
  for kk in range(a+1):
    k = a - kk
    num_success = k + (b - (a - k)) + 1
    num_fail = num_success + b + 1
    answer = min(answer, prod * num_success + (1 - prod) * num_fail)
    if p:
      prod = prod * p.pop(0)
  return answer

def main():
  t = int(raw_input())
  for i in range(t):
    print "Case #%d: %s" % (i + 1, str(solve()))

if __name__ == '__main__':
  main()
