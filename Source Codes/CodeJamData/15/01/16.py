def solve(P):
  sums = [0]
  for i in P:
    sums.append(int(i)+sums[-1])
  maxDif = 0
  for i,p in enumerate(sums):
    if i-p>maxDif:
      maxDif = i-p
  return maxDif
    

T = input()

for t in range(1,T+1):
  (S,Stab) = raw_input().split(' ')
  s = solve(Stab)
  print "Case #%d: %d" % (t,s)
