n = int(input())
b = list(map(int, input().split()))
ans = []
flag = True
for i in range(n):
  flag = True
  m = len(b)
  for j in range(m):
    if b[m-1-j] == m-j:
      ans.append(m-j)
      del b[m-1-j]
      flag = False
      break
  if flag:
    print(-1)
    break
if not flag:
  for i in range(n):
    print(ans[n-1-i])