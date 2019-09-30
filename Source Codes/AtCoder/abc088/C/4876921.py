c1 = list(map(int,input().split()))
c2 = list(map(int,input().split()))
c3 = list(map(int,input().split()))

t = True
if not(c1[0]-c2[0] == c1[1]-c2[1] == c1[2]-c2[2]):
  t = False
if not(c1[0]-c3[0] == c1[1]-c3[1] == c1[2]-c3[2]):
  t = False

if not(c1[0]-c1[1] == c2[0]-c2[1] == c3[0]-c3[1]):
  t = False
if not(c1[0]-c1[2] == c2[0]-c2[2] == c3[0]-c3[2]):
  t = False

if t:
  print("Yes")
else:
  print("No")