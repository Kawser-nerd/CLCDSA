from collections import defaultdict

n = int(input())
xs = list(map(int, input().split()))

def no():
    print("Impossible")
    quit(0)

def yes():
    print("Possible")
    quit(0)

cnts = defaultdict(int)
for x in xs:
    cnts[x] += 1

d = max(xs)
delems = []
for i in range(d+1):
    delems.append(max(i, d - i))

for delem in delems:
    if cnts[delem] <= 0:
        no()
    cnts[delem] -= 1

minx = min(delems) + 1
for x, rem in cnts.items():
    if rem > 0:
        if not minx <= x <= d:
            no()
yes()