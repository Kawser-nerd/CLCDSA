l = input().split()
N,Q = int(l[0]),int(l[1])
S = input()
blue = [0] * N
for k in range(1,N):
  if S[k-1] == 'A' and S[k] == 'C':
    blue[k] = blue[k-1] + 1
  else:
    blue[k] = blue[k-1]
for i in range(1,Q+1):
  rl = input().split()
  r = int(rl[0])
  l = int(rl[1])
  print(
    blue[l-1] - blue[r-1])