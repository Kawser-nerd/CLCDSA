import bisect

N = int(input())

D = [None]*N

for i in range(N):
  w,h = map(int, input().split())
  D[i] = (w,-h)

D.sort()

h = -D[0][1]
L = [h]

for i in range(1,N):
  h = -D[i][1]
  if (L[-1] < h):
    L.append(h)
  else:
    L[bisect.bisect_left(L, h)] = h
    
print(len(L))