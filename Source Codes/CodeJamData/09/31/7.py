#!/usr/bin/env python

from sys import stdin



def compute(numbers):
  if len(numbers) == 1:
    return 1
  numbers = list(numbers)
  base = max(2,len(set(numbers)))
  values = assignValues(numbers,1)
  #print str(values)
  power = 0
  accum = 0
  values.reverse()
  for v in values:
    accum += v * (base ** power)
    power+=1
  return accum

def assignValues(numbers, next):
  if len(numbers) == 0:
    return []
  if type(numbers[0]) != str:
    return [numbers[0]] + assignValues(numbers[1:],next)
  c = numbers[0]
  numbers = [next if x == c else x for x in numbers]
  if next == 1:
    next = 0
  elif next == 0:
    next = 2
  else:
    next+=1
  return [numbers[0]] + assignValues(numbers[1:], next)

cases = int(stdin.readline())

for caseNo in xrange(0, cases):
  number = stdin.readline().strip()
  result = compute(number)
  print "Case #%d: %s"%(caseNo+1, str(result))
