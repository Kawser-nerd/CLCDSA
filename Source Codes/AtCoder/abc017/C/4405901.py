N,m = map(int, input().split())
cry = [0 for i in range(m+1)] #??????????????
data = []
for i in range(N):
  li,ri,si = map(int, input().split())
  if not (li == 1 and ri == N):
    cry[li-1] += 1
    cry[ri] -= 1
    data.append([li,ri, si])
cur = 0
for i in range(m):
  cur += cry[i]
  cry[i] = cur
cry.remove(cry[-1])

res = []
small = min(cry)
if small == 0:
  count = 0
  for i in range(len(data)):
    count += data[i][2]
else:
  while small in cry:
    count = 0
    ind = cry.index(small)
    for i in range(len(data)):
      if not (data[i][0] <= ind+1 <= data[i][1]):
        count += data[i][2]
    cry[ind] = 10**6
    res.append(count)
  count = max(res)


print(count)