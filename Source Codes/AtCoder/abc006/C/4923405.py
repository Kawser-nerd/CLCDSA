N,M=map(int, input().split())
M2=M-3*N
if abs(M2)>N:
  print('-1 -1 -1')
elif M2>=0:
  print(0,N-M2,M2)
else:
  print(-M2,N+M2,0)