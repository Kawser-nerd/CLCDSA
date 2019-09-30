import itertools
l = list(map(int, (input().split())))
sm = []
for p in itertools.combinations(l, 3):
    sm.append(sum(p))
sm.sort(reverse=True)
print(sm[2])