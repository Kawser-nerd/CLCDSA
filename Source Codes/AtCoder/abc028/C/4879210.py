from itertools import combinations

a, b, c, d, e = map(int, input().split())

li = [sum(x) for x in combinations([a, b, c, d, e], 3)]

print(sorted(li, reverse=True)[2])