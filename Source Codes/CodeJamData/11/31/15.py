#!/usr/bin/python3
import math
import sys

def printe(*st):
    return True
#   sys.stderr.write(",".join([str(x) for x in st])+"\n")

def replace(st,pos,char):
   return st[0:pos] + char + st[pos+1:]   
def simulate():
   [r,c] = [int(a) for a in input().split()]
   t = []
   for b in range(r):
      t.append(input())
   printe(t)
   
   for y in range(r-1):
      x = 0
      while (x < c-1):
         if t[y][x]=='#' :
            if t[y][x+1]=='#' and t[y+1][x] == '#' and t[y+1][x+1] == '#':
               t[y] = replace(t[y],x,'/')
               t[y] = replace(t[y],x+1,"X")
               t[y+1] = replace(t[y+1],x,'X')
               t[y+1] = replace(t[y+1],x+1,'/')
               x += 1
            else:
               return "Impossible"
         x += 1
         
                 
   for y in range(r):
      if t[y][c-1] == '#':
         return "Impossible"
    
   for x in range(c):
      if t[r-1][x] == '#':
         return "Impossible"
      
   for y in range(r):
      t[y] = t[y].replace("X","\\")
   return "\n".join(t)
      
if __name__ == '__main__':
   for i in range(int(input())):
      print("Case #{}:\n{}".format(i+1,simulate()))
