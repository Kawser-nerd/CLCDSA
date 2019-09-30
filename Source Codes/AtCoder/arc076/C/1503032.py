R, C, N = map(int, input().split())

consider = []

def dist(x, y):
    if x == 0:
        return R * 2 + C + (C - y)
    if x == R:
        return R + y
    if y == 0:
        return x
    if y == C:
        return R + C + (R - x)
    
    
for i in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    if ((x1 == 0 or x1 == R) or (y1 == 0 or y1 == C)) and ((x2 == 0 or x2 == R) or (y2 == 0 or y2 == C)):
        consider.append((i, dist(x1, y1)))
        consider.append((i, dist(x2, y2)))

l = []
consider = sorted(consider, key=lambda p:p[1])

for c in consider:
    if len(l) == 0:
        l.append(c[0])
        continue
    elif c[0] == l[-1]:
        l.pop()
    else:
        l.append(c[0])

if len(l) == 0:
    print("YES")
else:
    print("NO")