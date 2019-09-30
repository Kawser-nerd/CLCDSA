N=input()
K=int(input())
res=0
for i in range(K):
  if not N[i] == "1":
    print(N[i])
    break
  else:
    res+=1
if res == K:
  print(1)