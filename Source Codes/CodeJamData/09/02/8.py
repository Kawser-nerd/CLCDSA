#!/usr/bin/env python

import sys, string

class Square:
  def __init__(self):
    self.height = -1
    self.sink = True
    self.links = []
    self.label = None
    self.parent = None

  def __repr__(self):
    return str(self.height)

def label_all(cur, label):
  cur.label = label
  for square in cur.links:
    label_all(square, label)
       
def find_top(cur):
  if cur.parent is None:
    return cur
  else:
    return find_top(cur.parent)

cases = int(sys.stdin.readline())

for case in xrange(1, cases + 1):
  dim = [int(num) for num in sys.stdin.readline().strip().split()]
  map = [[Square() for i in xrange(dim[1])] for j in xrange(dim[0])]
  for i in xrange(dim[0]):
    line = sys.stdin.readline().strip().split()
    for j in xrange(dim[1]):
      map[i][j].height = int(line[j])

  for i in xrange(dim[0]):
    for j in xrange(dim[1]):
      dirs = [(0, -1), (-1, 0), (1, 0), (0, 1)]
      drain = None
      for dir in dirs:
        r = i + dir[1]
        c = j + dir[0]
        if r < 0 or c < 0 or r >= dim[0] or c >= dim[1]:
          continue
        if map[r][c].height < map[i][j].height and (drain is None or map[r][c].height < drain.height):
          drain = map[r][c]
      if drain is not None:
        map[i][j].sink = False
        map[i][j].parent = drain
        drain.links.append(map[i][j])

  order = string.lowercase
  cur = 0
  for i in xrange(dim[0]):
    for j in xrange(dim[1]):
      if map[i][j].label is None:
        top = find_top(map[i][j])
        label_all(top, order[cur])
        cur += 1

  print 'Case #%d:' % case

  for i in xrange(dim[0]):
    for j in xrange(dim[1]):
      print map[i][j].label,
    print
