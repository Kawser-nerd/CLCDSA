sx, sy, tx, ty = map(int, input().split())
one = 'R'*(tx-sx)+'U'*(ty-sy)
two = 'L'*(tx-sx)+'D'*(ty-sy)
three = 'D'+'R'*(tx-sx+1)+'U'*(ty-sy+1)+'L'
four = 'U'+'L'*(tx-sx+1)+'D'*(ty-sy+1)+'R'
print(one+two+three+four)