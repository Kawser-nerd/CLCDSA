#!/usr/bin/python
#
# Tic-Tac-Toe-Tomek (Google Code Jam 2013 Qualification A)

import sys

inp=sys.stdin
cases=int(inp.readline())
for case in xrange(cases):
  grid=[]
  grid.append(inp.readline().strip())
  grid.append(inp.readline().strip())
  grid.append(inp.readline().strip())
  grid.append(inp.readline().strip())
  if case<cases-1:
    junk=inp.readline()
  winner=0
  fill=0
  for i in range(4):
    for j in range(4):
      if grid[i][j]!=".":
        fill+=1
  #rows
  for i in range(4):
    for player in ("XT","OT"):
      if (grid[i][0] in player and 
          grid[i][1] in player and 
          grid[i][2] in player and 
          grid[i][3] in player):
        winner=player[0]
  #columns
  for i in range(4):
    for player in ("XT","OT"):
      if (grid[0][i] in player and 
          grid[1][i] in player and 
          grid[2][i] in player and 
          grid[3][i] in player):
        winner=player[0]
  #diagonals
  for player in ("XT","OT"):
    if (grid[0][0] in player and 
        grid[1][1] in player and 
        grid[2][2] in player and 
        grid[3][3] in player):
      winner=player[0]
  for player in ("XT","OT"):
    if (grid[3][0] in player and 
        grid[2][1] in player and 
        grid[1][2] in player and 
        grid[0][3] in player):
      winner=player[0]
  if winner=="X" or winner=="O":
    print "Case #"+repr(case+1)+": "+winner+" won"
  elif fill==16:
    print "Case #"+repr(case+1)+": Draw"
  else:
    print "Case #"+repr(case+1)+": Game has not completed"
