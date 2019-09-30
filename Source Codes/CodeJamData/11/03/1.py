#!/usr/bin/python
#c.py
#Author: James Damore
#Created on: May 06, 2011
#Time-stamp: <2011-05-06 20:06:39>
#~/python/codeJam/c.py

def read_ints(lines = 1):
  if lines == 1: return map(int, raw_input().split())
  return [map(int, raw_input().split()) for _ in range(lines)]

def read_input():
    nBags = input()
    bags = read_ints()
    bitSum = reduce(lambda x, y: x ^ y, bags)
    if bitSum:
        return 'NO'
    return sum(bags) - min(bags)
    #return output


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    output = read_input()
    print "Case #%d:" % i, output
