import bisect
inpl = lambda: list(map(int,input().split()))
_ = int(input())
A = sorted(inpl())
Anlist = []
ap = 0
for a in A:
  if a > ap:
    Anlist.append([a,1])
    ap = a
  else:
    Anlist[-1][1] += 1

A = [ a for a,n in Anlist ]
N = len(Anlist)

ans = 0
for i in range(1,N+1):
  if Anlist[-i][1] == 0:
    continue
  
  p = len(bin(A[-i]))-3
  B = (1 << (p+1)) - A[-i]
  if A[-i] == B:
    ans += Anlist[-i][1]//2
  else:
    m = bisect.bisect_left(A,B,0,N-i)
    if m < N-i and A[m] == B:
      pairs = min(Anlist[m][1],Anlist[-i][1])
      ans += pairs
      Anlist[m][1] -= pairs

print(ans)