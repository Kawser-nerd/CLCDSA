T = int(raw_input())

for case in xrange(1, T+1):
  wires = []
  N = int(raw_input())
  for i in xrange(N):
    a,b = map(int, raw_input().split())
    wires.append((a,b))
  ans = 0
  for i in xrange(N):
    for j in xrange(i):
      temp = [wires[i], wires[j]] 
      temp.sort()
      if temp[0][1] > temp[1][1]:
        ans += 1
  print "Case #%d: %d" % (case, ans)
