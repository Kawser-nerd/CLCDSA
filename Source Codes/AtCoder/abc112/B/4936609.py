n, l = map(int, input().split())
c = []
t = []

for i in range(n):
    p = input().split()
    c.append(int(p[0]))
    t.append(int(p[1]))

args = []
for i in range(n):
    if t[i] <= l:
        args.append(i)

possibleTimes = []
for i in args:
    possibleTimes.append(c[i])

print("TLE" if possibleTimes == [] else min(possibleTimes))