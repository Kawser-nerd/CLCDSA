sx,sy,tx,ty = map(int,input().split())

dx = tx-sx
dy = ty-sy
ans = ''
ans = ans + 'U'*dy
ans = ans + 'R'*dx
ans = ans + 'D'*dy
ans = ans + 'L'*dx
ans = ans + 'L' + 'U'*(dy+1) + 'R'*(dx+1) + 'D'
ans = ans + 'R' + 'D'*(dy+1) + 'L'*(dx+1) + 'U'
print(ans)