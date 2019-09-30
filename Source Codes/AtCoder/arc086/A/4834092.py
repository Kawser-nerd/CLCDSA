N,K = map(int,input().split())
A = list(map(int,input().split()))
B = A.copy()
B = list(set(B))
n = len(B)

def counter(A):
 counter = {}
 for a in A:
  if(a in counter):
   counter[a] += 1
  else:
   counter[a] = 1
 return counter

ans = 0
if(n > K):
  dict = counter(A)
  count = 1
  #value?????
  for k, v in sorted(dict.items(), key=lambda x: -x[1]):
    if(count > K):
     ans += v
    count += 1
    
print(ans)