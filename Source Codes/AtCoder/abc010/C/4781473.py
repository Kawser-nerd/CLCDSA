txa,tya,txb,tyb,T,V = list(map(float, input().split()))
n=int(input())
XY=[list(map(int, input().split())) for _ in range(n)]

for x,y in XY:
  x1=txa-x
  y1=tya-y
  x2=txb-x
  y2=tyb-y
  
  if 4 * (x1**2+y1**2)*(x2**2+y2**2) <= ((T*V)**2 - (x1**2 + y1**2) - (x2**2 + y2**2))**2:
    print('YES')
    exit()
else:
  print('NO')