N = int(input())
C,S,F = [],[],[]
for i in range(N-1):
  Ci,Si,Fi = map(int,input().split())
  C.append(Ci)
  S.append(Si)
  F.append(Fi)
t = [0]*N

for i in range(N): #?i??????????j????
  for j in range(i, N-1):
    if t[i] % F[j] == 0 and t[i] >= S[j]:
      t[i] += C[j]
    elif t[i] < S[j]:
      t[i] = S[j]+C[j]
    elif t[i] >= S[j]:
      t[i] = ((t[i]-S[j])//F[j]+1)*F[j]+S[j]+C[j]
  print(t[i])
#    if j+1 == N:
#      break
#    train(i,j+1)