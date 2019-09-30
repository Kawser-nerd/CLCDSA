sx,sy,tx,ty=map(int,input().split())
dx=tx-sx
dy=ty-sy
root1='U'*dy+'R'*dx
root2='D'*dy+'L'*dx
root3='L'+'U'*(dy+1)+'R'*(dx+1)+'D'
root4='R'+'D'*(dy+1)+'L'*(dx+1)+'U'
print(root1+root2+root3+root4)