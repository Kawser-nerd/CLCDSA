n = int(input())
alist = list(map(int, input().split()))
maxa, mina = max(alist), min(alist)

ans = []
if abs(maxa) >= abs(mina):
  p = alist.index(maxa) + 1
  for i in range(n):
    alist[i] += maxa
    ans.append((p, i+1))
  for i in range(n-1):
    alist[i+1] += alist[i]
    ans.append((i+1, i+2))
else:
  p = alist.index(mina) + 1
  for i in range(n):
    alist[i] += mina
    ans.append((p, i+1))
  for i in range(n-2, -1, -1):
    alist[i] += alist[i+1]
    ans.append((i+2, i+1))

print(len(ans))
for a in ans:
  print(*a)