import sys
import string
letters = string.lowercase

Mod = 1000000007
              
tests = int(sys.stdin.readline())

for test in range (tests):


  n = int(sys.stdin.readline())
  a = sys.stdin.readline().split()


  res = 1


  for l in letters:
    b = 0
    sb = ""
    e = 0
    se = ""
    m = 0
    sm = ""
    tres = 1
    for i in range(len(a)):
      if a[i] != "" and l in a[i]:
        s = a[i]
        if s[0] == l and s[-1] == l:
          m += 1
          sm += s
          tres = tres * m % Mod
          a[i] = ""
        elif (s[0] == l):
          b += 1
          sb += s
          a[i] = ""
        elif (s[-1] == l):
          e += 1
          se += s
          a[i] = ""
      if b > 1 or e > 1:
        tres = 0
    if se + sm + sb != "": 
      a.append(se + sm + sb)
      res = res * tres % Mod
#  print a, res

  for l in letters:
    cur = 0
    for s in a:
      if l in s:
        cur += 1
    if cur > 1:
      res = 0
  k = 1
  
  d = dict()
  
  for i in range (len (a)):
    if a[i] != "":
      res = res * k % Mod;
      k += 1
      ts = a[i] 
      for l in letters:
        d[l] = 0
      d[ts[0]] = 1
      for i in range (1, len(ts)):
        if ts[i] != ts[i-1]:
          d[ts[i]] += 1
      for l in letters:
        if d[l] > 1:
          res = 0

  print "Case #" + str(test + 1) + ": " + str(res)
    
