n, w = map(int, input().split())
wd = {}
minw, v = map(int, input().split())
wd[minw] = [v]
wd[minw+1] = []
wd[minw+2] = []
wd[minw+3] = []
for _  in range(n-1):
  _w, v = map(int, input().split())
  wd[_w].append(v)

for k, v in wd.items():
  wd[k] = list(sorted(v))[::-1]

maxw = 0
for i in range(w // minw + 1):
  for j in range((w - minw * i) // (minw + 1) + 1):
    for k in range((w - minw * i - (minw + 1) * j) // (minw + 2) + 1):
      l = (w - minw * i - (minw + 1) * j - (minw + 2) * k) // (minw + 3)
      tmp = sum(wd[minw][:i]) + sum(wd[minw+1][:j]) + sum(wd[minw+2][:k]) + sum(wd[minw+3][:l])
      if tmp > maxw:
        maxw = tmp
print(maxw)