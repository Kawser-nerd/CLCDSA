N = int(input())

for i in range(N):
  d = int(input())
  if(i==0):
    dmin = d
    dmax = d
  else:
    if(dmin<=d and dmax >=d):
      dmin = 0
    else:
      dmin = min(abs(dmin-d),abs(dmax-d))
    dmax +=d

print(dmax)
print(dmin)