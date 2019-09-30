n = int(input())
nim = 0
for _ in range(n):
    x, y, z = map(int, input().split())
    m = int(input())
    xmin = 10**16
    ymin = 10**16
    zmin = 10**16
    xmax = 0
    ymax = 0
    zmax = 0
    for _ in range(m):
      a,b,c = map(int, input().split())
      xmin = min(xmin,a)
      xmax = max(xmax,a)
      ymin = min(ymin,b)
      ymax = max(ymax,b)
      zmin = min(zmin,c)
      zmax = max(zmax,c)
    xup = xmin 
    xdo = x - xmax -1
    yup = ymin 
    ydo = y - ymax-1
    zup = zmin
    zdo = z - zmax-1
    nim = nim^xup^xdo^yup^ydo^zup^zdo
if nim !=0:
  print("WIN")
else:
  print("LOSE")