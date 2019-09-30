#!/usr/bin/env python2.5
import sys

class blank(object):
  def __init__(self, dict = None):
    if dict:
      self.__dict__.update(dict)

def solve(flavors, customers):
  unhappy = set()
  for i, c in enumerate(customers):
    if not c.unmalt:
      unhappy.add(i)

  # state is set unhappy, sets cust...unmalt, and values flav...val
  while unhappy:
    i = unhappy.pop()
    f = customers[i].malt
    if f is None:
      return False
    flavors[f].val = 1
    unhappy.difference_update(flavors[f].malters)
    for j in flavors[f].unmalters:
      customers[j].unmalt.discard(f)
      m = customers[j].malt
      if (not customers[j].unmalt and
          not (m is not None and flavors[m].val)):
        unhappy.add(j)

  return True

def run(irun):
  n = int(sys.stdin.readline())
  m = int(sys.stdin.readline())
  flavors = [blank({'val':0, 'malters':set(), 'unmalters':set()})
             for _ in xrange(n)]
  customers = [blank() for _ in xrange(m)]
  for i, c in enumerate(customers):
    c.malt = None
    c.unmalt = set()
    line = sys.stdin.readline().split()[1:]
    while line:
      flav  = int(line.pop(0)) - 1
      sense = int(line.pop(0))
      if sense:
        c.malt = flav
        flavors[flav].malters.add(i)
      else:
        c.unmalt.add(flav)
        flavors[flav].unmalters.add(i)

  ans = solve(flavors, customers)
  if ans:
    print "Case #%d:" % irun,
    for f in flavors:
      print f.val,
    print
  else:
    print "Case #%d: IMPOSSIBLE" % irun

def main():
  N = int(sys.stdin.readline())
  for i in xrange(N):
    run(i+1)

if __name__ == '__main__':
  main()
