from __future__ import with_statement
import re, heapq
import sys

class Board:
  
  def __init__(self,r,c):
    self.nr = r
    self.nc = c
    self.grid = 0
  def copy(self):
    nb = Board(self.nr, self.nc)
    nb.grid = self.grid
    return nb
  def setBurned(self,r,c):
    self.grid |= (1<<(r*self.nc+c))
  def getBurned(self,r,c):
    if r >= self.nr or r < 0 or c >= self.nc or c < 0:
      return True
    return self.grid & (1 << (r*self.nc+c)) != 0

def getMovements(board, king):
  row, col = king
  blah = [
    (row, col - 1),
    (row, col + 1),
    (row-1, col),
    (row+1, col),
    (row-1, col-1),
    (row-1, col+1),
    (row+1, col+1),
    (row+1, col-1)
  ]
  result = [x for x in blah if not board.getBurned(*x)]
  return result

memoize = {}
def doMinimax(board, king):
  moves = getMovements(board, king)
  memomoo = (board.grid, king)
  if memomoo in memoize:
    return memoize[memomoo]

  for move in moves:
    nb = board.copy()
    nb.setBurned(*king)
    r = not doMinimax(nb, move)
    if r:
      memoize[memomoo] = True
      return True
  memoize[memomoo] = False
  return False

def main():
  global memoize
  with open(sys.argv[1]) as f:
    for case in xrange(int(f.readline())):
      r,c = [int(x) for x in re.split(r'\s+', f.readline().strip())]
      board = Board(r,c)
      king = None
      for row in xrange(r):
        line = f.readline().strip()
        for col in xrange(c):
          x = line[col]
          if x == '#':
            board.setBurned(row,col)
          if x == 'K':
            king = (row,col)
      memoize = {}
      didAliceWin = doMinimax(board, king)
      print "Case #%d: %s"%(case+1, 'A' if didAliceWin else 'B')
main()
