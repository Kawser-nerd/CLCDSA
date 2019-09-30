#!/usr/bin/env python
# Google Code Jam 2008 round 1A, Task A
# Solution by Sebastian Hagen
# language: Python 2.5
# This program reads input from stdin and writes output to stdout.

import sys

if (__name__ == '__main__'):
   tc_count = int(sys.stdin.readline().strip())
   for i in range(tc_count):
      sys.stdin.readline() # don't care
      v1 = [int(x) for x in sys.stdin.readline().strip().split()]
      v2 = [int(x) for x in sys.stdin.readline().strip().split()]
      v1.sort()
      v2.sort()
      v2.reverse()
      msp = 0
      assert (len(v1) == len(v2))
      for j in range(len(v1)):
         msp += v1[j]*v2[j]
      
      sys.stdout.write('Case #%d: %d\n' % (i+1, msp))
