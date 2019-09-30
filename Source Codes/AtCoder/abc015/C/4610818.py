import itertools
N,K = map(int,input().split())
T = []
judge = 0 #0:bug??

for i in range(N):
  t = input().split()
  for j in range(K):
   t[j] = int(t[j])
  T.append(t)

# *T = T[0],T[1],...,T[K] 
# itertools.product : ??
tmp = itertools.product(*T)
tmp = list(tmp)

for i in range(len(tmp)):
  a = list(tmp[i])
  for j in range(len(a)):
   if(j == 0):
    b = a[j]
   else:
    b = b^a[j]
  if(b == 0):
    judge = 1 # bug ?
    break
  
if(judge == 0):
  print('Nothing')
else:
  print('Found')