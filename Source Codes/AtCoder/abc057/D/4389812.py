n, a, b = map(int, input().split())
vlist = list(reversed(sorted(map(int, input().split()))))

cc = [[0 for _ in range(51)] for _ in range(51)]
for i in range(51):
  for j in range(i+1):
    if j == 0 or j == i:
      cc[i][j] = 1
    else:
      cc[i][j] = cc[i-1][j-1] + cc[i-1][j]

avg = sum(vlist[:a]) / a
avaln, avalp = 0, 0
for i in range(n):
  if vlist[i] == vlist[a-1]:
    avaln += 1
    if i < a:
      avalp += 1

cnt = 0
if avalp == a:
  for ap in range(a, b+1):
    cnt += cc[avaln][ap]
else:
  cnt += cc[avaln][avalp]

print('%.8f' % avg)
print(cnt)