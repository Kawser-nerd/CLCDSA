n = int(input())
slist = [0]
for a in map(int, input().split()):
  slist.append(slist[-1] + a)
slist.append(slist[-1] + pow(10, 9) + 5)

prevs = None
c = 0
ans = 0
for s in sorted(slist):
  if prevs is None:
    prevs = s
    c = 1
  else:
    if prevs == s:
      c += 1
    else:
      ans += (c * (c - 1)) // 2
      c = 1
      prevs = s

print(ans)