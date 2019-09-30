n, k, l = map(int, input().split())

ar = [i for i in range(n)]
ah = [0 for _ in range(n)]
br = [i for i in range(n)]
bh = [0 for _ in range(n)]

def root(l, i):
  if l[i] == i:
    return i
  else:
    l[i] = root(l, l[i])
    return l[i]

def union(l, h, i, j):
  ip = root(l, i)
  jp = root(l, j)
  if ip == jp:
    return
  else:
    if h[ip] < h[jp]:
      l[ip] = jp
    elif h[ip] > h[jp]:
      l[jp] = ip
    else:
      if ip < jp:
        l[jp] = ip
        h[ip] += 1
      else:
        l[ip] = jp
        h[jp] += 1

for _ in range(k):
  p, q = map(int, input().split())
  if p < q:
    union(ar, ah, p-1, q-1)
  else:
    union(ar, ah, q-1, p-1)

for _ in range(l):
  r, s = map(int, input().split())
  if r < s:
    union(br, bh, r-1, s-1)
  else:
    union(br, bh, s-1, r-1)

abd = {}
for a, b in zip(ar, br):
  if (root(ar, a), root(br, b)) in abd:
    abd[(root(ar, a), root(br, b))] += 1
  else:
    abd[(root(ar, a), root(br, b))] = 1

for a, b in zip(ar, br):
  print(abd[(root(ar, a), root(br, b))])