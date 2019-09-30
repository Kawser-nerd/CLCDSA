A,B,K = map(int,input().split())
ans = []
for i in range(K):
  ans.append(A + i)
  if A + i >= B:
    break
for i in range(K):
  ans.append(B - i)
  if B - i <= A:
    break
ans = sorted(set(ans))
for a in ans:
  print(a)