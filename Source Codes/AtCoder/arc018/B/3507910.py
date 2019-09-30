from itertools import combinations as comb
def tri(o):
  (x1,y1),(x2,y2),(x3,y3)=o
  return abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)

n,v=int(input()),0
l=tuple(tuple(map(int,input().split())) for _ in range(n))
for s in map(tri,comb(l,3)):
  if s%2==0 and s:v+=1
print(v)