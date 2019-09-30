from collections import Counter

N, M = map(int, input().split(" "))
NAME = input()
KIT = input()

name = Counter(NAME)
kit = Counter(KIT)
# print(name, kit)
# print(name.keys())
if len(name.keys()-kit.keys()) == 0:
    print(max(-(-v//kit[k]) for k, v in name.items()))
else:
    print(-1)