ax,ay,bx,by,cx,cy = map(int,input().split())
print(abs((bx-ax)*(cy-ay)-(by-ay)*(cx-ax))/2)