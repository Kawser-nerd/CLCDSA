T = int(raw_input())
for test_case in range(T):
  [J, P, S, K] = [int(x) for x in raw_input().split()]
  answer = J * P * min(S,K)
  print "Case #%s: %s"%(test_case+1, answer)
  for j in range(J):
    for p in range(P):
      for s in range(min(S,K)):
        print j+1, p+1, (s+j+p)%S + 1
