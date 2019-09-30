N,K = map(int,input().split())
A = list(map(int,input().split()))
plusminus = [0]*len(A)
plusor0 = [0]*len(A)
plusminus[0] = A[0]
plusor0[0] = max(0,A[0])
for i in range(1,N):
  plusminus[i] = plusminus[i-1]+A[i]
  plusor0[i] = plusor0[i-1]+max(0,A[i])
plusminus.insert(0,0)
plusor0.insert(0,0)
ans = 0
for i in range(N-K+1):
  s = plusminus[i+K]-plusminus[i]
  if i == 0:
    s += plusor0[N]-plusor0[K]
  elif i == N-K:
    s += plusor0[N-K]
  else:
    s += plusor0[i]+plusor0[N]-plusor0[i+K]
  if ans <= s:
    ans = s
for i in range(N-K+1):
  s = 0
  if i == 0:
    s += plusor0[N]-plusor0[K]
  elif i == N-K:
    s += plusor0[N-K]
  else:
    s += plusor0[i]+plusor0[N]-plusor0[i+K]
  if ans <= s:
    ans = s
print(ans)