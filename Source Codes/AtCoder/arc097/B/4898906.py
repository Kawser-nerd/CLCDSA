n, m = map(int, input().split())
plist = list(map(int, input().split()))

ufp = [i for i in range(n)]
ufs = [1 for _ in range(n)]

def root(i):
  pi = i
  while ufp[pi] != pi:
    pi = ufp[pi]
    ufp[pi] = root(pi)
  return pi

def union(i, j):
  pi, pj = root(i), root(j)
  if pi == pj:
    return
  if ufs[pi] < ufs[pj]:
    ufp[pi] = pj
  elif ufs[pj] < ufs[pi]:
    ufp[pj] = pi
  else:
    if pi < pj:
      ufp[pj] = pi
      ufs[pi] += 1
    else:
      ufp[pi] = pj
      ufs[pj] += 1

for _ in range(m):
  x, y = map(int, input().split())
  union(x-1, y-1)

ans = 0
for i, p in enumerate(plist):
  if root(i) == root(p-1):
    ans += 1

print(ans)