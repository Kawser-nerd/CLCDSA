n=int(input())
L=[2,1]
if n<2:
  print(L[-1])
else:
  for i in range(n-1):
    L.append(L[i]+L[i+1])
  print(L[-1])