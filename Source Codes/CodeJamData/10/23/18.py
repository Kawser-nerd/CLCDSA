#!/usr/bin/python

import math

memo = {}
fmemo = {}

def comb(x1, x2, slots):
   key = str(x2-x1)+","+str(slots)
   if key not in fmemo:
      fmemo[key] = (math.factorial(x2-x1)/math.factorial(slots)/math.factorial(x2-x1-slots)) % 100003

   return fmemo[key]      
      


def count(digits, n):
   key = str(digits)+","+str(n)
   if key in memo:
      return memo[key]
   elif digits == 1:
      return 1
   elif digits == 2:
      return 1
   elif digits == 3:
      return n-3;
   elif digits == n-1:
      return 1;
   else:
      ct  = 0
      for i in range (1,digits):
         if digits-i > n-digits:
            continue
         ct += count(i,digits)*comb(digits,n-1,digits-i-1)
      memo[key] = ct % 100003
      return ct % 100003



if __name__ == "__main__":
   fp = open('data.in')

   fp.readline()
   cases = 1

   for i in fp.readlines():   
      n = int(i)
      ct = 0
      for i in range (1,n):
         ct += count(i,n)
      print "Case #%d: %d" % (cases,ct%100003)
      cases += 1
