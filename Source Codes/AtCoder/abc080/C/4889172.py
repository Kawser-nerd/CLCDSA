N = int(input())
F = [list(map(int,input().split())) for i in range(N)]
P = [list(map(int,input().split())) for i in range(N)]

ans = -(10**7) * 10 * 100

for i in range(1,2**10):  
  counter = [0]*N #?i?joisino????????
  tmp = 0 #  
  for j in range(10):    
    if (i>>j) & 1:
      for k in range(N):
        if F[k][j] ==1:
          counter[k] += 1
  for l in range(N):
    tmp += P[l][counter[l]]
      #tmp += P[k][counter[k]]
  ans = max(tmp,ans)
print(ans)