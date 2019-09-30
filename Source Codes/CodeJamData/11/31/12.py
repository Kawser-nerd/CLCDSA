#!/usr/bin/python

import sys

fp = open(sys.argv[1], 'r')

num_cases = int(fp.readline())

for i in range(0, num_cases):
   words = fp.readline().split()
   R, C = int(words[0]), int(words[1])

   print "Case #" + str(i+1) + ":"

   grid = [None] * R
   for j in range(0, R):
      grid[j] = [None] * C

   for j in range(0, R):
      line = fp.readline()
      for k in range(0, C):
         grid[j][k] = line[k]

   if R < 2 or C < 2:
      if grid[0][0] == '.':
         print '.'
         continue
      else:
         print "Impossible"
         continue

   flag = False
   for j in range(0, R):
      for k in range(0, C):
         if grid[j][k] == '#':
            grid[j][k] = '/'
            if j+1 == R:
               flag = True
               break
            else:
               if grid[j+1][k] == '#':
                  grid[j+1][k] = '\\'
               else:
                  flag = True
                  break
            if k+1 == C:
               flag = True
               break
            else:
               if grid[j][k+1] == '#':
                  grid[j][k+1] = '\\'
               else:
                  flag = True
                  break
               if grid[j+1][k+1] == '#':
                  grid[j+1][k+1] = '/'
               else:
                  flag = True
                  break
   if flag == True:
      print "Impossible"
   else:
      for j in range(0, R):
         print "".join(grid[j])
