#!/usr/bin/env python

def solve():
  won = {'X': False, 'O': False}
  board = [raw_input() for x in xrange(4)]
  dxa = [0, +1, 0, -1, +1, +1, -1, -1]
  dya = [+1, 0, -1, 0, +1, -1, +1, -1]
  can = False
  for i in xrange(8):
    dx = dxa[i]
    dy = dya[i]
    for sx in xrange(4):
      for sy in xrange(4):
        for sym in ['X', 'O']:
          x = sx
          y = sy
          cur = 0
          while x>=0 and y>=0 and x<4 and y<4:
            if board[x][y]==sym or board[x][y]=='T':
              cur += 1
              if cur == 4: won[sym] = True
            else:
              cur = 0
            x += dx
            y += dy
  for i in board:
    for j in i:
      if j == '.':
        can = True
  if won['X'] and not won['O']: return "X won"
  if won['O'] and not won['X']: return "O won"
  if won['X'] and won['O'] or not can: return "Draw"
  return "Game has not completed"

for test in xrange(1,1+int(raw_input())):
  if test <> 1:
    raw_input()
  print "Case #" + str(test) + ": " + str(solve())

