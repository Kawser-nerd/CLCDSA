T = int(raw_input())

def ifStarts(i, R, k, N, g):
      # if i is at the head of the queue,
      # how many people ride, which group next
      t = g[i]
      j = (i + 1) % N
      while t + g[j] <= k and j != i:
        t = t + g[j]
        j = (j + 1) % N
      return (t, j)

for case in xrange(1, T + 1):
  R, k, N = [int(x) for x in raw_input().split()]
  g       = [int(x) for x in raw_input().split()]
  if max(g) > k:
    res = 0
  else:
    visited = set([])
    i = 0
    while i not in visited:
      visited.add(i)
      i = ifStarts(i, R, k, N, g)[1]
    #print i
    # i is now the first part we loop from
    c = 1
    p,j = ifStarts(i, R, k, N, g) # p will count people who ride in a loop
    while j != i:
      x, j = ifStarts(j, R, k, N, g)
      c += 1
      p += x
    # c is now the number of rides before we get back to i
    a = 0
    r = 0
    res = 0
    enteredLoop = False
    doneLoop    = False
    while r < R:
      if not enteredLoop:
        #print a, r, res
        re, a = ifStarts(a, R, k, N, g)
        res += re
        r += 1
        if a == i:
          enteredLoop = True
      elif not doneLoop:
        #print a, r, res
        loopsToDo = (R-r)/c
        r += loopsToDo * c
        res += p * loopsToDo
        doneLoop = True
      else:
        #print a, r, res
        re, a = ifStarts(a, R, k, N, g)
        res += re
        r += 1
    #print a, r, res, re
    #print i
  print "Case #" + str(case) + ":", res
