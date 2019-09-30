import bisect
N,T = map(int,input().split())
L = []
for i in range(N):
  L.append(int(input()))
zen = []
def Base_10_to_n(X,n):
  if (int(X/n)):
    return Base_10_to_n(int(X/n),n)+str(X%n)
  return str(X%n)
n = 2
P = []
Q = []
ans = 0
for i in range(N//2):
  P.append(L[i])
for j in range(N//2,N):
  Q.append(L[j])
if N%2 == 0:
  for X in range(n**(N//2)):
    STR = Base_10_to_n(X,n).zfill(N//2)
    cur = 0
    for i in range(N//2):
      if STR[i] == '1':
        cur += P[i]
    zen.append(cur)
  zen.sort()
  for X in range(n**(N//2)):
    STR = Base_10_to_n(X,n).zfill(N//2)
    sub = 0
    for i in range(N//2):
      if STR[i] == '1':
        sub += Q[i]
    k = bisect.bisect_left(zen,T-sub)
    l = bisect.bisect_right(zen,T-sub)
    ans += l-k
else:
  for X in range(n**(N//2)):
    STR = Base_10_to_n(X,n).zfill(N//2)
    cur = 0
    for i in range(N//2):
      if STR[i] == '1':
        cur += P[i]
    zen.append(cur)
  zen.sort()
  for X in range(n**(N//2+1)):
    STR = Base_10_to_n(X,n).zfill(N//2+1)
    sub = 0
    for i in range(N//2+1):
      if STR[i] == '1':
        sub += Q[i]
    k = bisect.bisect_left(zen,T-sub)
    l = bisect.bisect_right(zen,T-sub)
    ans += l-k
print(ans)