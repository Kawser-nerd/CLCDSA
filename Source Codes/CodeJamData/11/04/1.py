#!/usr/bin/python
#d.py
#Author: James Damore
#Created on: May 06, 2011
#Time-stamp: <2011-05-06 20:21:44>
#~/python/codeJam/d.py

def read_ints(lines = 1):
  if lines == 1: return map(int, raw_input().split())
  return [map(int, raw_input().split()) for _ in range(lines)]

def read_input():
    length = input()
    array = read_ints()

    return sum((int(i + 1 != v) for i, v in enumerate(array)))
    

numCases=input()
for i in range(1, numCases+1):
    #read_input()
    output = read_input()
    print "Case #%d:" % i, output
