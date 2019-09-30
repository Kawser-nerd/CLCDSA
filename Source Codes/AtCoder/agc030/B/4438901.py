L, N = list(map(int, input().split()))
X = [int(input()) for i in range(N)]
Y = [L - X[i] for i in range(N)]

RL = [0]
RSL = [0]
for i in X:
  RL.append(i)
  RSL.append(RSL[-1] + i)

LL = [0]
LSL = [0]
for i in X[::-1]:
  LL.append(L - i)
  LSL.append(LSL[-1] + (L - i))

D = [RSL[i] + LSL[N - i] for i in range(N + 1)]

Ans = max(RL[N], LL[N])
for i in range(1, N):
  if i < (N + 1) // 2:
    k = N - 2 * i
    t = (D[i] - LSL[max(k - 1, 0)]) * 2  - LL[N - i]
    s = (D[i] - LSL[k]) * 2  - RL[i]
    Ans = max(Ans, t, s)
  else:
    k = 2 * i - N
    t = (D[i] - RSL[max(k - 1, 0)]) * 2  - RL[i]
    s = (D[i] - RSL[k]) * 2  - LL[N - i]
    Ans = max(Ans, t, s)
  
print(Ans)