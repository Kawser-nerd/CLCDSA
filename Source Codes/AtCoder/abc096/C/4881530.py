H, W = map(int, input().split())
canvas = [str(input()) for _ in range(H)]

def check_border(x, y):
  return 0<=x and x<W and 0<=y and y<H

def can_draw(x, y):
  a = 1 if check_border(x-1,y) and canvas[y][x-1]=='#' else 0
  b = 1 if check_border(x+1,y) and canvas[y][x+1]=='#' else 0
  c = 1 if check_border(x,y-1) and canvas[y-1][x]=='#' else 0
  d = 1 if check_border(x,y+1) and canvas[y+1][x]=='#' else 0
  return 0 < a+b+c+d
        

def solve():
  for y in range(H):
    for x in range(W):
      if  ((canvas[y][x]=='#') and (not can_draw(x, y))): return False
  return True

print('Yes' if solve() else 'No')