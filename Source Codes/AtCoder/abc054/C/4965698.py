n, m = map(int, input().split())
l = [[] for _ in range(n)]
for i in range(m):
  a, b  = map(int, input().split())
  l[a-1].append(b-1)
  l[b-1].append(a-1)

import itertools
ans = 0
for p in itertools.permutations(range(n)):
    if p[0] == 0:
        flag = True
        for i in range(n-1):
            if not p[i+1] in l[p[i]]:
                flag = False
        if flag:
            ans += 1
print(ans)