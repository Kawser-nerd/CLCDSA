N,a = map(int,input().split())
k = input()
B = list(map(int,input().split()))
L = []
TF = [False]*N
cur = B[a-1]
iden = 0
for i in range(N):
  if TF[cur-1] == False:
    TF[cur-1] = True
    L.append(cur)
    cur = B[cur-1]
  else:
    iden = cur
    break
if len(L) != len(B):
  LOOP = []
  for j in range(len(L)):
    if L[j] == cur:
      LOOP = L[j:len(L)]
      break
  if int(k) <= len(L):
    print(L[int(k)-1])
  else:
    k = str(int(k)-len(L))
    mod = len(LOOP)
    ans = 0
    for n in map(int,k):
      ans = (ans*10+n)%mod
    if ans == 0:
      print(LOOP[len(LOOP)-1])
    else:
      print(LOOP[ans-1])
else:
  mod = len(L)
  ans = 0
  for n in map(int,k):
    ans = (10*ans+n)%mod
  if ans == 0:
    print(L[len(L)-1])
  else:
    print(L[ans-1])