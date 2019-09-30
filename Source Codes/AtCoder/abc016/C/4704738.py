N, M = list(map(int, input().split()))
A, B = [], []
for _ in range(M):
  a, b = list(map(int, input().split()))
  A.append(a)
  B.append(b)
  
_dict = {i:set() for i in range(1,N+1)}

for a,b in zip(A,B):
  _dict.get(a, set()).add(b)
  _dict.get(b, set()).add(a)

for n in range(1,N+1):
  s=set()
  for f1 in _dict[n]:
    s=s|_dict[f1]
  s=s-_dict[n]-set([n])
  print(len(s))