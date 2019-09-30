from collections import Counter

N, M = map(int, input().split())

name = input().rstrip()
kit = input().rstrip()

name_counter = Counter(name)
kit_counter = Counter(kit)

for key in name_counter:
    if kit_counter[key] == 0:
        print(-1)
        exit()

ans = 0

for key, val in name_counter.items():
    d = kit_counter[key]
    ans = max(ans, (d + val - 1) // d)



print(ans)