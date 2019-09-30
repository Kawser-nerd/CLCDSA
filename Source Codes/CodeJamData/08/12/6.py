#!/usr/bin/env python
# Google Code Jam 2008 round 1A, Task B
# Solution by Sebastian Hagen
# language: Python 2.5
# This program reads input from stdin and writes output to stdout.

import sys

class HornClause:
   def __init__(self, neglist, pos):
      self.neg = set(neglist)
      self.pos = pos
   
   @classmethod
   def build_list_from_file(cls, f):
      n = int(f.readline().strip())
      c = int(f.readline().strip())
      rv = []
      for i in range(c):
         nl = []
         pos = None
         ll = [int(x) for x in f.readline().strip().split()[1:]]
         while (ll):
            var = int(ll.pop(0))
            negated = int(ll.pop(0))
            if (negated):
               if (pos):
                  raise ValueError
               pos = var
            else:
               nl.append(var)
         
         rv.append(cls(nl, pos))
      
      return (rv, n)
   

def hc_test(hc_list, n):
   pos_var = set()
   emptyset = set()
   
   
   for hc in hc_list:
      if ((hc.neg == emptyset) and (hc.pos)):
         pos_var.add(hc.pos)
   c = True
   while (c):
      c = False
      for hc in hc_list:
         if (hc.neg.difference(pos_var) == emptyset):
            if (hc.pos is None):
               return False
            if (not (hc.pos in pos_var)):
               c = True
            pos_var.add(hc.pos)
   
   rv = [False]*n
   for i in pos_var:
      rv[i-1] = True
   
   return rv

if (__name__ == '__main__'):
   tc_count = int(sys.stdin.readline().strip())
   for i in range(tc_count):
      (hc_list, n) = HornClause.build_list_from_file(sys.stdin)
      res = hc_test(hc_list, n)
      if (res is False):
         res = 'IMPOSSIBLE'
      else:
         res = ' '.join(['%d' % x for x in res])
      
      sys.stdout.write('Case #%d: %s\n' % (i+1, res,))



