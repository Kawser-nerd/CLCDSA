from collections import defaultdict

import string

#f = open('test', 'r')
f = open('C-small-1-attempt0.in', 'r')

T = int(f.readline())

nums = [2, 3, 4, 5]
tuples = [(x, y, z) for x in nums for y in nums for z in nums]

def card_dict(t):
  ret = defaultdict(int)
  x, y, z = t
  ret[1] += 1
  ret[x] += 1
  ret[y] += 1
  ret[z] += 1
  ret[x*y] += 1
  ret[y*z] += 1
  ret[x*z] += 1
  ret[x*y*z] += 1
  return ret
  
lookup = {t: card_dict(t) for t in tuples}

#print lookup

for test in range(1, T+1):
#  print line.split()
  R, N, M, K = [int(num) for num in f.readline().split()]
  
  print 'Case #' + str(test) + ': '
  
  for x in range(R):
    prods = [int(num) for num in f.readline().split()]
    bestscore = 0
    bestt = None
    for t in tuples:
      curscore = 1
      for prod in prods:
	curscore *= lookup[t][prod]
      if curscore > bestscore:
	bestscore = curscore
	bestt = t
    
    #print prods, bestscore, bestt
    
    print string.join([str(x) for x in bestt], '')

