import sys
from numpy import *
      
def get_nums(n):
  nums = []
  tot = 0
  while tot < n:
    next = [ int(x) for x in (raw_input()).split(' ') ]
    tot += len(next)
    nums.extend(next)

  return nums

def solve1(R, C, empty):
  allj = 'c' + '.'*(empty-1) + '*'*( R*C-empty)
  
  if R == 1:
    return allj
  if C == 1:
    return '\n'.join(allj)

def solve2(R, C, empty):
  if (empty > 1 and empty % 2 == 1) or (empty == 2):
    return 'Impossible'
  board = zeros( (R,C), int)
  if empty == 1:
    pass
  elif R == 2:
    for col_idx in range(0, empty / 2):
      board[0][col_idx] = -1
      board[1][col_idx] = -1
  elif C == 2:
    for row_idx in range(0, empty / 2):
      board[row_idx][0] = -1
      board[row_idx][1] = -1

  board[0][0] = 1

  return board
  
def solveN(R,C, empty):

  #print R,C,empty
  if (empty == 2) or ( (empty < 9) and (empty > 1) and (empty % 2 == 1)):
    return 'Impossible'
    
  board = zeros( (R,C), int)
  if empty == 1:
    pass
  elif empty >= 2*R+2*C - 4:
    left = empty
    while left > 0:
      for start in range(0, min(R,C)):
        if left == 0:
          break
        for col in range(start, C):
          if left == 0:
            break
          board[start][col] = -1
          left -= 1
        for row in range(start+1, R):
          if left == 0:
            break
          board[row][start] = -1
          left -= 1
    
  elif empty % 2 == 0:

    left = empty
    for cc in range(0,2):
      for rr in range(0, 2):
        board[rr][cc] = -1
        left -= 1

    for cc in range(2, C):
      if left == 0:
        break

      board[0][cc] = -1
      board[1][cc] = -1

      left -= 2
      
    for rr in range(2, R):
      if left == 0:
        break

      board[rr][0] = -1
      board[rr][1] = -1

      left -= 2

  else:
    left = empty
    for cc in range(0,3):
      for rr in range(0,3):
        board[rr][cc] = -1
        left -= 1
    
    for cc in range(3, C):
      if left == 0:
        break

      board[0][cc] = -1
      board[1][cc] = -1

      left -= 2

    for rr in range(3, R):
      if left == 0:
        break

      board[rr][0] = -1
      board[rr][1] = -1

      left -= 2
      
  board[0][0] = 1
  #print board
  return board

def convert_board(board, R, C):
  final = []
  #print board
  for rr in range(0,R):
    cr = ''
    for cc in range(0,C):

      p = board[rr][cc]
      if p == -1:
        cr += '.'
      elif p == 0:
        cr += '*'
      else:
        cr += 'c'

    final.append(cr)

  return final

def main():
  nt = int(raw_input())

  for test_idx in range(1,nt+1):
    print 'Case #%d:' % test_idx
    
    R,C,M = get_nums(3)
    #print R,C,R*C-M
    if R == 1 or C == 1:
      print solve1(R,C,R*C-M)
      continue
      
    elif R == 2 or C == 2:
      board = solve2(R,C,R*C-M)

    else:
      board = solveN(R,C,R*C-M)

    if board == 'Impossible':
      print board
    else:
      final = convert_board(board, R, C)
      for row in final:
        print row
    


if __name__ == '__main__':
  main()
  
