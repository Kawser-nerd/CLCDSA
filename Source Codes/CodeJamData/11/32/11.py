#!/usr/bin/python

import sys

fp = open(sys.argv[1], 'r')

num_cases = int(fp.readline())

for i in range(0, num_cases):
   words = fp.readline().split()
   L, t, N, C = int(words[0]), int(words[1]), int(words[2]), int(words[3])
   a_i = words[4:]
   a_i = [int(w) for w in a_i]

   path = [None] * N

   k = 0
   for j in range(0, N):
      path[j] = 2 * a_i[k]
      k = (k+1) % C

   path_opt = path[:]

   for j in range(0, N):
      if t >= path_opt[j]:
         path_opt[j] = 0
         t -= path[j]
      else:
         path_opt[j] -= t
         path[j] = t
         path = path[0:j+1]
         path_opt = path_opt[j:]
         break

   path_opt.sort()

   speedup = []

   if L > len(path_opt):
      speedup = path_opt
      path_opt = []
   else:
      speedup = path_opt[len(path_opt) - L:]
      path_opt = path_opt[0: len(path_opt) - L]
   
   ans = 0
   
   for p in path:
      ans += p
   for p in path_opt:
      ans += p
   for p in speedup:
      ans += p / 2.0
   
   print "Case #" + str(i+1) + ": " + str(int(ans))
