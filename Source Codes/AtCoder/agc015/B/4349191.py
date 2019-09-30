S = input()
N = len(S)
cnt = 0
for i in range(N):
  if S[i] == 'U':
    cnt += N+i-1
  else:
    cnt += 2*N-i-2
print(cnt)