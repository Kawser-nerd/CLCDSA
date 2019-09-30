N,K = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
def gcd(a,b):
  if a%b != 0:
    return gcd(b,a%b)
  else:
    return b
cur = A[0]
for i in range(N):
  cur = gcd(A[i],cur)
if max(A) < K:
  print('IMPOSSIBLE')
else:
  if K%cur != 0:
    print('IMPOSSIBLE')
  else:
    print('POSSIBLE')