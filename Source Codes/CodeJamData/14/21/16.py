#!/usr/bin/python

import sys

t=int(sys.stdin.readline())
for caseno in xrange(t):
  n=int(sys.stdin.readline())
  strings=[]
  uc=[]
  rep=[]
  for j in xrange(n):
    mystring=sys.stdin.readline().strip()
    #break each string into a list of unique characters and repeat counts
    uc.append([])
    rep.append([])
    last=""
    for letter in mystring:
      if letter==last:
        rep[-1][-1]+=1
      else:
        uc[-1].append(letter)
        rep[-1].append(1)
        last=letter
  #Make sure all the strings have the same sequence of unique letters
  possible=True
  for j in xrange(1,n):
    if uc[0]!=uc[j]:
      possible=False
  if possible:
    moves=0
    #Compute smallest number of moves to equalize each character
    for ltr in xrange(len(uc[0])):
      vals=[]
      for j in xrange(n):
        vals.append(rep[j][ltr])
      fewest=99999999999
      for ct in xrange(min(vals),max(vals)+1):
        movesthisct=0
        for v in vals:
          movesthisct+=abs(v-ct)
        if movesthisct<fewest:
          fewest=movesthisct
      moves+=fewest
    sys.stdout.write("Case #"+repr(caseno+1)+": "+repr(moves)+"\n")
  else:
    sys.stdout.write("Case #"+repr(caseno+1)+": Fegla Won\n")
