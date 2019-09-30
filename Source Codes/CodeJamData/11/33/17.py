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
   [n,l,h] = [int(a) for a in input().split()]
   orchestra = [int(a) for a in input().split()]
   
   notes = []
   for i in range(l,h+1):
      notes.append(i)
   
   for l in orchestra:
      i = 0
      while i<len(notes):
         if notes[i] % l == 0 or l % notes[i] == 0:
            i+=1
         else:
            notes.pop(i)
   
      printe(notes)
   if len(notes)==0:
      return "NO"
   else:
      return notes[0]
    
      
if __name__ == '__main__':
   for i in range(int(input())):
      print("Case #{}: {}".format(i+1,simulate()))
