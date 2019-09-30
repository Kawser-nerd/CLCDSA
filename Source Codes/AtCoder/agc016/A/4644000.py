s = input()
L = []
for i in s:
  if i not in L:
    L.append(i)

Ans = 100
for i in L:
  cnt = 0
  ma = 0
  for j in s:
    if i != j:
      cnt += 1
    else:
      ma = max(ma, cnt)
      cnt = 0
  ma = max(ma, cnt)
  Ans = min(Ans, ma)

print(Ans)