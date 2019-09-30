#!/usr/bin/python
#
# Fair and Square - Google Code Jam 2013 Qualifying C
#
# Generate all palindromes up to 10^7, and check whether their squares are palindromes.

import sys

def reverse(n):
  #Reverse number n
  g=list(str(n))
  if g[-1]=="L":
    g=g[:-1]
  g.reverse()
  h="".join(g)
  return int(h)

def ispalindrome(n):
  #Determine if n is a palindrome
  return n==reverse(n)

fairandsquare=[]

#generate palindromes in ascending order of number of digits
for i in range(1,10):
  sq=i*i
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(1,10):
  j=i*10+reverse(i)
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(10,100):
  j=i*10+reverse(int(i/10))
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(10,100):
  j=i*100+reverse(i)
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(100,1000):
  j=i*100+reverse(int(i/10))
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(100,1000):
  j=i*1000+reverse(i)
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)
for i in range(1000,10000):
  j=i*1000+reverse(int(i/10))
  sq=j*j
  if ispalindrome(sq):
    fairandsquare.append(sq)

def howmany(n):
  #Find how many fair and square numbers are less than or equal to n
  #Use binary search to be able to find it quickly even if the list is long
  if n<fairandsquare[0]:
    return 0
  if n>=fairandsquare[-1]:
    return len(fairandsquare)
  low=0
  high=len(fairandsquare)-1
  while low+1<high:
    mid=int((low+high)/2)
    if n<fairandsquare[mid]:
      high=mid
    else:
      low=mid
  return low+1

inp=sys.stdin
cases=int(inp.readline())
for case in xrange(cases):
  interval=inp.readline().strip().split()
  low=int(interval[0])
  high=int(interval[1])
  print "Case #"+repr(case+1)+": "+repr(howmany(high)-howmany(low-1))
