#!/usr/bin/python3.1
# -*- coding: utf-8 -*-
import sys

base = ['Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F']

T = int(sys.stdin.readline())

for t in range(T):
  data = sys.stdin.readline().strip().split(" ")
  pos = 0
  n = int(data[pos])
  combine = {} # dictionary
  for i in range(n):
    pos += 1
    pair = data[pos][:2]
    nov = data[pos][2]
    combine[pair] = combine[pair[::-1]] = nov
  pos += 1
  n = int(data[pos])
  opposed = set()
  for i in range(n):
    pos += 1
    opposed.add(data[pos])
    opposed.add(data[pos][::-1])
  # print('combine:', combine)
  # print('opposed:', opposed)
  # print('invoke:', data[-1])
  sez = ""
  for c in data[-1]:
    sez += c
    if len(sez) >= 2 and sez[-2:] in combine:
      sez = sez[:-2] + combine[sez[-2:]]
    elif len(sez) >= 2:
      destroy = False
      for w in sez[:-1]:
        if w+sez[-1] in opposed:
          destroy = True
          break
      if destroy: sez = ""
  print('Case #%i:' % (t+1), "[" + ", ".join(x for x in sez) + "]")
