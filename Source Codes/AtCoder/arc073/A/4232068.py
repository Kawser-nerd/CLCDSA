N,T = map(int,input().split())
L = input().split()
M = list(map(int,L))
s = M[N-1]
M.append(s)
ans = 0
c = 0
k = 0
while c<N:
  if M[c]+T >= M[c+1]:
    c += 1
    k += 1
  else:
    if k == 0:
      ans += T
      c += 1
    else:
      ans += T+M[c]-M[c-k]
      c += 1
      k = 0
ans += T+M[c]-M[c-k]
print(ans)