from __future__ import with_statement
import re, heapq
import sys



def addlBowlsFor(mixture, mixtures, unusedBowls = 0, p=False):
  if mixture.islower():
    return 0

  ingreds = mixtures[mixture]
  ingredLeastUse = sorted(ingreds,None, lambda x: addlBowlsFor(x, mixtures, unusedBowls))

  bowlsINeed = 0
  big = 0
  for ingred in reversed(ingredLeastUse):
    if ingred.isupper():
      addlBowls = addlBowlsFor(ingred, mixtures, unusedBowls, p)
      unusedBowls += addlBowls - 1
      bowlsINeed += addlBowls

  if unusedBowls == 0:
    bowlsINeed += 1

  return bowlsINeed


def doWork(first, mixtures):
  return addlBowlsFor(first, mixtures,0,True )

def main():
  with open(sys.argv[1]) as f:
    cases = int(f.readline())
    for i in xrange(cases):
      mixtureCount = int(f.readline())
      first = None
      mixtures = {}
      for mi in xrange(mixtureCount):
        data = f.readline().strip()
        data = re.split(r'\s+',data)
        if not first:
          first = data[0]
        mixtures[data[0]] = data[2:]
      result = doWork(first, mixtures) 
      print "Case #%d: %d"%(i+1,result)


main()
