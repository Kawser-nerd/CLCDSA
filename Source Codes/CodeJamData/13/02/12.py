#!/usr/bin/python
#
# Lawnmower - Google Code Jam 2013 Qualification B

import sys
status=["NO","YES"]

inp=sys.stdin
cases=int(inp.readline())
for case in xrange(cases):
  lawnsize=inp.readline().split()
  rows=int(lawnsize[0])
  columns=int(lawnsize[1])
  lawn=[]
  for r in xrange(rows):
    lawnrow=[]
    rowdata=inp.readline().split()
    for c in xrange(columns):
      lawnrow.append(int(rowdata[c]))
    lawn.append(lawnrow)
  rowheights=[]
  colheights=[]
  for r in xrange(rows):
    rowheights.append(max(lawn[r]))
  for c in xrange(columns):
    cmax=0
    for r in xrange(rows):
      if lawn[r][c]>cmax:
        cmax=lawn[r][c]
    colheights.append(cmax)
  ok=1
  for r in xrange(rows):
    for c in xrange(columns):
      if lawn[r][c]!=min(rowheights[r],colheights[c]):
        ok=0
        break
    if ok==0:
      break
  print "Case #"+repr(case+1)+": "+status[ok]
