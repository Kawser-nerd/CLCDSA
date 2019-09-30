N, M = map(int, input().split())
import math
name = input()
kit = input()
names = list(set(name))
kits = list(set(kit))
for i in range(N):
    if (name[i] in kit) == 0:
        print(-1)
        quit()
ans = 0
for i in range(len(names)):
    ans = max(ans, math.ceil(name.count(names[i])/kit.count(names[i])))
print(ans)