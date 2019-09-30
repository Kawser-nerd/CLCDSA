N,x = map(int,input().split())
if x == 1:
  print('No')
elif x == 2*N-1:
  print('No')
else:
  print('Yes')
  if N == 2:
    for i in range(1,4):
      print(i)
  else:
    if x != 2*N-2:
      L = []
      M = [x+2,x-1,x,x+1]
      for i in range(1,2*N):
        if not i in M:
          L.append(i)
      for j in range(N-2):
        print(L[j])
      for k in range(4):
        print(M[k])
      for l in range(N-3):
        print(L[l+N-2])
    else:
      L = []
      M = [x-2,x,x+1,x-1]
      for i in range(1,2*N):
        if not i in M:
          L.append(i)
      for j in range(N-2):
        print(L[j])
      for k in range(4):
        print(M[k])
      for l in range(N-3):
        print(L[l+N-2])