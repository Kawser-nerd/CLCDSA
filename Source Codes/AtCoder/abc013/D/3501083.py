N, M, D = map(int, input().split())
A = [int(x) for x in input().split()]
S = [i for i in range(N)]
Q = [0] * N
for a in A:
  swap = S[a]
  S[a] = S[a - 1]
  S[a - 1] = swap
for i, s in enumerate(S):
  Q[s] = i
L = [0] * N
for q in range(N):
  if L[q] == 0:
    P = [q]
    nq = q
    while Q[nq] != q:
      nq = Q[nq]
      P.append(nq)
    k = D % len(P)
    for i, p in enumerate(P):
      L[p] = P[(i + k) % len(P)] + 1
for l in L:
  print(l)