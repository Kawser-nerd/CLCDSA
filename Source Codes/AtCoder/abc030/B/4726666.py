n,m=map(int,input().split())
if abs((30*n+0.5*m)-6*m)%360==180:
  print(180)
  exit()
if abs((30*n+0.5*m)-6*m)%360==0:
  print(0)
  exit()
if abs((30*n+0.5*m)-6*m)%360<180:
  print(abs((30*n+0.5*m)-6*m)%360)
else:
  print(360-abs((30*n+0.5*m)-6*m)%360)