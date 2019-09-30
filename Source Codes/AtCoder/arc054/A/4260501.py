L,X,Y,S,D = map(int,input().split())
C = 0
AC = 0
if D >= S:
  C = D-S
  AC = L-C
else:
  AC = S-D
  C = L-AC
VC = X+Y
VAC = abs(X-Y)
if X-Y < 0:
  if C/VC <= AC/VAC:
    print(C/VC)
  else:
    print(AC/VAC)
else:
  print(C/VC)