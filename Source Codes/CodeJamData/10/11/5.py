#!/usr/bin/python3

from fractions import gcd
from functools import reduce

t = int(input())

for c in range(1, t + 1):
  n, k = input().split(' ')
  n, k = int(n), int(k)

  g = []
  for i in range(n):
    l = input()
    l = l.replace('.', '')
    while len(l) < n:
      l = '.' + l
    g.append(l)

  q = {'R': False, 'B': False, '.': False}

  for i in range(n):
    for j in range(n):
      for di in range(-1, 2):
        for dj in range(-1, 2):
          if di or dj:
            ok = True
	    
            x = i
            y = j

            for kk in range(k - 1):
              x += di
              y += dj

              if x < 0 or y < 0 or x >= n or y >= n or g[x][y] != g[i][j]:
                ok = False
                break
	    
            if ok:
              q[g[i][j]] = True
  
  if q['R'] and q['B']:
    str = 'Both'
  elif q['R']:
    str = 'Red'
  elif q['B']:
    str = 'Blue'
  else:
    str = 'Neither'

  print('Case #%d: %s' % (c, str))
 
