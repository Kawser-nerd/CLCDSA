#!/usr/bin/python3
import math
import sys

def printe(*st):
    return True
    sys.stderr.write(",".join([str(x) for x in st])+"\n")
   
def generator(N,l):
   a = 0
   i = 0
   while a<N:
      yield l[i]
      i+=1
      if i==len(l):
         i=0
      a+=1


def simulate():
    l = [int(a) for a in input().split()]
    L = l.pop(0)
    t = l.pop(0)
    N = l.pop(0)
    C = l.pop(0)
    printe(l)
    
    sum = 0 
    pfactory = []
    firstBuilt = False
    for star in generator(N,l):       
       if sum > t:
          pfactory.append(star)
          if not firstBuilt:
             firstBuilt = True
             pfactory.append((sum - t) / 2)
       sum += star*2
       printe(star)
       
    if sum > t:
          if not firstBuilt:
             pfactory.append((sum - t) / 2)
             
    pfactory.sort(reverse=True)
    printe("pf",pfactory)
    for i in range(L):
       if i >= len(pfactory):
          break
       sum -= pfactory[i]
    return int(sum)
    
      
if __name__ == '__main__':
   for i in range(int(input())):
      print("Case #{}: {}".format(i+1,simulate()))
