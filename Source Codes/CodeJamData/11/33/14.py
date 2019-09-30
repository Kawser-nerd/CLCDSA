#!/usr/bin/python

import sys

fp = open(sys.argv[1], 'r')

num_cases = int(fp.readline())

for i in range(0, num_cases):
   words = fp.readline().split()
   N, L, H = int(words[0]), int(words[1]), int(words[2])

   words = fp.readline().split()
   nums = [int(w) for w in words]

   flag = False
   
   ans = -1

   for j in range(L, H + 1):
      for n in nums:
         if j % n != 0 and n % j != 0:
            flag = True
            break
      if flag == False:
         ans = j
         break
      else:
         flag = False
   
   if ans == -1:
      print "Case #" + str(i+1) + ": NO"
   else:
      print "Case #" + str(i+1) + ": " + str(ans)
