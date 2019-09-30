N, M = map(int, input().split())
 
K = 4*N - M
if M < 2*N or 4*N < M:
  print(-1,-1,-1)
else:
  for i in range(N):
    if (K - i) % 2 == 0:
      l = i
      k = int((K - l) / 2)
      m = int(N - k - l)
      print(k,l,m)
      break
    else:
      pass