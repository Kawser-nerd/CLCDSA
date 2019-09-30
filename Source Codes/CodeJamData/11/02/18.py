import sys
import os

lines = open("b2.in", "r").readlines()
t = int(lines[0].strip())
for ti in range(1,t+1):
  items = lines[ti].strip().split(" ")
  combine = {}
  opposed = {}
  n1 = int(items[0])
  for i in range(1, n1+1):
    combine[(items[i][0],items[i][1])] = items[i][2]
    combine[(items[i][1],items[i][0])] = items[i][2] 
  n2 = int(items[n1+1])
  for i in range(n1+2, n1+2+n2):
    opposed[(items[i][0], items[i][1])] = True
    opposed[(items[i][1], items[i][0])] = True
  #n3 = int(items[n1+2+n2])
  s = items[n1+3+n2]
  ans = []
  for ch in s:
    while (True):
      if ans == []:
        ans.append(ch)
        break
      last = ans.pop()
      if ((last, ch) in combine):
        ch = combine[(last, ch)]
        continue
      ans.append(last)
      do_clear = False
      for i in ans:
        if (i, ch) in opposed:
          do_clear = True
      if do_clear == False:
        ans.append(ch)
        break
      else:
        ans = []
        break
  s = ""
  for i in ans:
    if (s!=""):
      s = s + ", "
    s = s + i
  print "Case #%d: [%s]" % (ti, s)
      
