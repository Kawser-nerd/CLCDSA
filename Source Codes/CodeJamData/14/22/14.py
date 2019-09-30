#!/usr/bin/python

import sys

cache={}

def tobinary(x):
  res=""
  while x>0:
    if x%2==1:
      res="1"+res
      x-=1
    else:
      res="0"+res
    x/=2
  return res

def solve(a,b,k):
  if cache.has_key((a,b,k)):
    return cache[(a,b,k)]
  if a=="" and b=="":
    return 1
  elif a=="":
    return int(b,2)+1
  elif b=="":
    return int(a,2)+1
  elif (len(a)<len(k) or (len(a)==len(k) and a<k)) or (
      len(b)<len(k) or (len(b)==len(k) and b<k)):
    z=(int(a,2)+1)*(int(b,2)+1)
    cache[(a,b,k)]=z
    return z
  elif len(a)>len(b):
    #split into cases for a having its high bits on or off
    excess=len(a)-len(b)
    head=a[:excess]
    a1=a[excess:]
    a2="1"*len(a1)
    while len(a1)>0 and a1[0]=="0":
      a1=a1[1:]
    z=solve(a1,b,k)+int(head,2)*solve(a2,b,k)
    cache[(a,b,k)]=z
    return z
  elif len(b)>len(a):
    return solve(b,a,k)
  else:
    #a and b same length and not smaller than k
    #consider all four cases for first bits of each
    a1=a[1:]
    a2="1"*len(a1)
    while len(a1)>0 and a1[0]=="0":
      a1=a1[1:]
    b1=b[1:]
    b2="1"*len(b1)
    while len(b1)>0 and b1[0]=="0":
      b1=b1[1:]
    if len(a)==len(k):
      k1=k[1:]
      while len(k1)>0 and k1[0]=="0":
        k1=k1[1:]
      case1=solve(a1,b1,k1)
    else:
      case1=0
    z=case1+solve(a2,b1,k)+solve(a1,b2,k)+solve(a2,b2,k)    
    cache[(a,b,k)]=z
    return z

t=int(sys.stdin.readline())
for caseno in xrange(t):
  lin=sys.stdin.readline().split()
  a=int(lin[0])-1
  b=int(lin[1])-1
  k=int(lin[2])-1
  ba=tobinary(a)
  bb=tobinary(b)
  bk=tobinary(k)
  cache={}
  sys.stdout.write("Case #"+repr(caseno+1)+": "+repr(solve(ba,bb,bk))+"\n")
