N, Q = map(int,input().split())
li = [0]*N
for i in range(Q):
  r, l, t = map(int,input().split())
  for j in range(r-1,l,1):
    li[j] = t
for i in range(N):
  print(li[i])