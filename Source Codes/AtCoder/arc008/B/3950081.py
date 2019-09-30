from collections import Counter

N, M = map(int, input().split())
name = input()
kit = input()

diff = Counter(name)
ans = 0
for item in set(name):
    if item not in set(kit):
        ans = -1
        break
else:
    while len(diff) != 0:
        diff = diff - Counter(kit)
        ans += 1

print(ans)