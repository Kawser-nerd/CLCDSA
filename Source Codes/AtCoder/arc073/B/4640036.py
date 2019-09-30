n, w = map(int, input().split())
di = dict()
m = 0
for _ in range(n):
  x,y = map(int, input().split())
  if x not in di:
    di[x] = []
  di[x].append(y)
for i in di:
  di[i].sort(reverse=True)
a = min(di.keys())
b,c,d = a+1,a+2,a+3
for i in b,c,d:
  if i not in di:
    di[i] = []
for i in range(len(di[a])+1):
  for j in range(len(di[b])+1):
    for k in range(len(di[c])+1):
      for l in range(len(di[d])+1):
        if i*a + j*b + k*c + l*d <= w:
          m = max(m, sum(di[a][:i] + di[b][:j] + di[c][:k] + di[d][:l]))
print(m)