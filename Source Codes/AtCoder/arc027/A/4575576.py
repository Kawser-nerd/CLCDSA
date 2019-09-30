h, m = map(int, input().split())
now = 60 * h + m
mongen = 18 * 60
rest = mongen - now
print(rest)