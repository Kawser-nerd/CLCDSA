#!/usr/bin/python2
#-*- coding: utf-8 -*-

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

E = 0
R = 0

def update(maybe, must, i, D):
  j = i - 1
  m = maybe[i]
  while j >= 0:
    m -= R
    if m < must[j]:
      break
    must[j] = m
    j -= 1

  j = i + 1
  m = must[i]
  while j < len(maybe):
    m += R
    if m > maybe[j]:
      break
    maybe[j] = m
    j += 1

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  E, R, N = readarray(int)
  V = readarray(int)

  D = [-1] * N
  maybe = [E] * N
  must = [0] * N
  tasks = list(reversed(sorted([(V[i], i) for i in range(N)])))
  
  best = 0

  for v, i in tasks:
    best += v * (maybe[i] - must[i])
    D[i] = maybe[i] - must[i]
    update(maybe, must, i, D)
  print best
