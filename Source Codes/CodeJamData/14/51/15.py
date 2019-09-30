n = int(raw_input())
for testcase in range(n):
  [N,p,q,r,s] = [int(x) for x in raw_input().split()]
  transistors = [(i*p+q)%r + s for i in range(N)]
  transistorsum = sum(transistors)
  first = 0
  last = N
  firstsum = 0
  lastsum = 0
  minimax = transistorsum
  while last-first != 1:
    nextfirstsum = firstsum + transistors[first]
    nextlastsum = lastsum + transistors[last-1]
    if nextfirstsum < nextlastsum:
      firstsum += transistors[first]
      first += 1
    else:
      last -= 1
      lastsum += transistors[last]
    currentmax = max([firstsum,lastsum,transistorsum-firstsum-lastsum])
    minimax = min(currentmax,minimax)
  answer = float(transistorsum - minimax) / float(transistorsum)
  print "Case #%d: %.10f"%(testcase+1,answer)
