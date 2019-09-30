import sys
import string
from fractions import gcd
import math

P = 1000000007
alpha = list(string.ascii_lowercase)

with open("in.in", "r") as f:
 with open("out.txt", "w") as fout:
  T = int(f.readline())
  for t in range(T):
    line = f.readline()
    n = int(line.strip())
    line = f.readline()
    a = line.strip().split()
    d = {}
    res = 1
    for x in alpha:
      d[x] = [0,0,0]
    aa = []
    for x in a:
      c = x[0]
      full = True
      for y in x:
        if y != c:
          full = False
      if full:
        d[c][1] += 1
      else:
        aa.append(x)
        d[x[0]][0] += 1
        d[x[-1]][-1] += 1
    #print aa
    #print d
    a = aa
    for x in alpha:
      for i in range(1,d[x][1]+1):
        res = (res * i) % P
      d[x][1] = 1 if d[x][1] > 0 else 0
    pos = True
    k = 0
    for x in alpha:
      if d[x][0] > 1 or d[x][2] > 1:
        pos = False
      k += (d[x][0] >0 and d[x][2] > 0)
    n = len(a)
    if not pos or (k == n and n > 0):
      print >> fout, "Case #%d: %d" % (t+1, 0)  
      continue
    fr = n - k
    #print k, fr, res
    for i in range(1,fr+1):
      res = (res * i) % P
    for x in alpha:
      if d[x][1] > 0 and d[x][0]+d[x][2] == 0:
        res = (res * (fr+1)) % P
        fr += 1
    #print res
    if len(a)>0:
     while len(a)>1:
      ff = False
      for i, x in enumerate(a):
       for j, y in enumerate(a):
        if x[-1] == y[0] and i != j:
          ff = True
          break
       if ff:
         break
      if not ff:
        i,j = 0, 1
      try:
        ns = a[i]+a[j]
      except:
        print t, i, j, len(a), ff
        exit()
      if i>j:
        i,j = j,i
      #print i,j,a
      a = a[:i]+a[i+1:j]+a[j+1:] + [ns]
     test = a[0]
     good = True
     us = {}
     for x in alpha:
      us[x] = 0
     #print >> sys.stderr, test
     for i in range(1,len(test)):
      c = test[i]
      if test[i] != test[i-1]:
        us[test[i-1]] = 1
        if us[test[i]] == 1:
          res = 0
          #print i
          #print test[:i]
          #print test[i:]
          break 
    print >> fout, "Case #%d: %d" % (t+1, res)  





