N = int(input())
A = map(int, input().split())
S = sorted([[a, i] for i, a in enumerate(A)], key=lambda x: x[0], reverse=True)
S.append([0, N])
B = [0 for i in range(N)]
num = S[0][1]
for i in range(1, N + 1):
  if S[i - 1][0] > S[i][0]:
   B[num] += (S[i - 1][0] - S[i][0]) * i
  num = min(num, S[i][1])
for b in B:
  print(b)