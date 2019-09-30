#!/usr/bin/python
from sys import stdin

def gcd(a,b):
  while b>0: a,b = b,a%b
  return a

TTT = int(stdin.readline())
for ttt in range(1,TTT+1):
  D, T = map(int,stdin.readline().split())
  data = []
  for t in range(T):
    row = map(int,stdin.readline().split())
    row[0] = 1
    for i in range(len(row)): row[i] -= 1
    row.append(D+7)
    data.append(row)
  last_avail = [0] * T
  sum = 0
  day = 0
  while 1:
    # process the current day
    ways = [0] * (T+1)
    ways[0] = 1
    for t in range(T):
      good, bad = last_avail[t]+1, D-last_avail[t]-1
      for c in range(T,-1,-1):
        if c>0:
          ways[c] = ways[c]*bad + ways[c-1]*good
        else:
          ways[c] = ways[c]*bad
    cur_day = 0
    for i in range(T+1): cur_day += i*i*ways[i]
    sum += cur_day
    # check whether I can skip the rest
    ok = 1
    for i in range(T):
      if last_avail[i] < len( data[i] )-2:
        ok = 0
    if ok:
      sum += (D-1-day) * cur_day
      break
    # move to the next day
    day += 1
    if day==D: break
    for i in range(T):
      if data[i][ last_avail[i]+1 ]==day:
        last_avail[i] += 1
  nom, denom = sum, D**T
  div = gcd(nom,denom)
  nom, denom = nom/div, denom/div
  whole = nom / denom
  nom %= denom
  print "Case #%d: %d+%d/%d" % (ttt,whole,nom,denom)

