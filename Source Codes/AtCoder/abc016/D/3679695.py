Ax,Ay,Bx,By=map(int,input().split())
N=int(input())
Board=[[int(i) for i in input().split()] for i in range(N)]
Board.append(Board[0])
ans=0
for i in range(N):
  x1,y1=Board[i]
  x2,y2=Board[i+1]
  D=-(Bx-Ax)*(y2-y1)+(By-Ay)*(x2-x1)
  if D!=0:
    t=(-(x1-Ax)*(y2-y1)+(y1-Ay)*(x2-x1))/D
    s=((Bx-Ax)*(y1-Ay)-(By-Ay)*(x1-Ax))/D
    if 0<t<1 and 0<s<1:
      ans+=1
print(ans//2+1)