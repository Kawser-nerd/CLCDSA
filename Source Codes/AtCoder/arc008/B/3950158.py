from collections import Counter

N, M = map(int, input().split())
name = input()
kit = input()

ans = 0
if len(set(name) - set(kit)) != 0:
    ans = -1
else:
    diff = Counter(name)
    while len(diff) != 0:
        diff = diff - Counter(kit)
        ans += 1

print(ans)