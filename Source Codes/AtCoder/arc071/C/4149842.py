S = input()
T = input()
N = len(S)
M = len(T)
Ss = [0]*(N+1)
Ts = [0]*(M+1)
for i in range(N):
  if S[i] == "A":
    temp = 1
  else:
    temp = -1
  Ss[i+1] = Ss[i] + temp
for i in range(M):
  if T[i] == "A":
    temp = 1
  else:
    temp = -1
  Ts[i+1] = Ts[i] + temp
Q = int(input())
for i in range(Q):
  a, b, c, d = (int(i) for i in input().split())
  if (Ss[b] - Ss[a-1] - Ts[d] + Ts[c-1])%3==0:
    print("YES")
  else:
    print("NO")