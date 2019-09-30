from itertools import combinations

n = int(input())
s = input().strip()

cand = ['AA', 'AB', 'AX', 'AY', 'BA', 'BB', 'BX', 'BY', 'XA', 'XB', 'XX', 'XY', 'YA', 'YB', 'YX', 'YY',]
minl = 1000
for c1, c2 in combinations(cand, 2):
  tmps = s
  tmps = tmps.replace(c1, 'L').replace(c2, 'R')
  if len(tmps) < minl:
    minl = len(tmps)

print(minl)