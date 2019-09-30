import math

lines = open("input.txt").readlines()
cases = int(lines[0])

base = 100003
count = [0,0,[0,1]]

cnk = [[1]]
for i in xrange(501):
  cnk.append([1])
  for j in xrange(1,i):
    cnk[i].append((cnk[i-1][j-1] + cnk[i-1][j]) % base)
  cnk[i].append(1)

for n in xrange(3, 501):
  #print n
  count.append([0,1])
  for k in xrange(2,n):
    c = 0
    for j in xrange(max(1,2*k-n),k):
      c += (count[k][j] * cnk[n-k-1][k-j-1]) % base
    count[n].append(c)

#print count

def getCount(n):
  global count
  total = 0
  for k in xrange(1,n): total += count[n][k]
  return total % base

for case in xrange(1, cases + 1):
    n = int(lines[case])
    print "Case #%d: %d" % (case, getCount(n))
    
