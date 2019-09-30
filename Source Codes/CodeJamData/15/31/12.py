T = int(raw_input())

for testcase in range(T):
  [r,c,w] = [int(x) for x in raw_input().split()]
  answer = r*(c/w) + w - (1 if c%w == 0 else 0)
  print "Case #%s: %s" %(testcase+1, answer)
