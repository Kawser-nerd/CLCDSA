n = int(input())
a = []
b = []
for _ in [0]*n:
  a += [list(map(int,input().split()))]
a.sort(key=lambda t:-t[0])
for _ in [0]*n:
  b += [list(map(int,input().split()))]
b.sort(key=lambda s:s[1])
c = 0
for t in a:
  for s in b:
    if t[0]<s[0] and t[1]<s[1]:
      c += 1
      b.remove(s)
      break
print(n-len(b))