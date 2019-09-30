N = int(input())
W = [input() for _ in range(N)]

flag = True
if N == len(set(W)):
  for i in range(1, N):
    if W[i - 1][-1] != W[i][0]:
      flag = False
      break
else:
  flag = False
print('Yes' if flag else 'No')