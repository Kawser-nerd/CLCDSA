def hersCode(L, n):
  ok = len(L) - 1
  ng = 0
  while abs(ok - ng) > 1:
    mid = abs(ok + ng) // 2
    if L[mid] > n:
      ok = mid
    else:
      ng = mid
  return ok

def hersCode2(L, n):
  ok = 0
  ng = len(L)
  while abs(ok - ng) > 1:
    mid = abs(ok + ng) // 2
    if L[mid] < n:
      ok = mid
    elif L[mid] == n:
      if TF[mid]:
        ok = mid
      else:
        ng = mid
    else:
      ng = mid
  return ok

N = int(input())

A = list(map(int, input().split()))
A.sort()

D = [pow(2, i) for i in range(31)]
TF = [True for i in range(N + 1)]
Ans = 0
A = [-1e11] + A
for i in range(len(A) - 1, 1, -1):
  if TF[i]:
    k = D[hersCode(D, A[-1])] - A[-1]
    del A[-1]
    t = hersCode2(A, k)
    if A[t] == k:
      TF[t] = False
      Ans += 1
  else:
    del A[-1]

print(Ans)