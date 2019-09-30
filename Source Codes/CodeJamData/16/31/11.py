def alphabet(i):
  alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
  return alphabet[i]

T = int(raw_input())
for test_case in range(T):
  N = int(raw_input())
  P = [[alphabet(i), int(x)] for i,x in enumerate(raw_input().split())]
  answer = ""
  while sum(p[1] for p in P) > 3:
    P.sort(key=lambda x: x[1], reverse=True)
    answer += "%s%s "%(P[0][0], P[1][0])
    P[0][1], P[1][1] = P[0][1]-1, P[1][1]-1
  if sum(p[1] for p in P) == 3:
    P.sort(key=lambda x: x[1], reverse=True)
    answer += "%s "%P[0][0]
    P[0][1] = P[0][1]-1
  if sum(p[1] for p in P) == 2:
    letter = [x[0] for x in P if x[1] > 0]
    answer += "%s%s "%(letter[0], letter[1])
    P[0][1], P[1][1] = P[0][1]-1, P[1][1]-1    
    
  print "Case #%s: %s"%(test_case+1, answer)
