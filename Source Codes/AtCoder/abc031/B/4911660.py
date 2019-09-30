# ??
L,H=map(int,input().split())
N=int(input())

# ???
l=[]

for i in range(N):
  # ??
  x=int(input())

  if x<L:
    l.append(L-x)
  elif L<=x and x<=H:
    l.append(0)
  else:
    l.append(-1)

# ??
for x in l:
  print(x)