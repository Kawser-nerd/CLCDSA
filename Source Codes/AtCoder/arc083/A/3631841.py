A,B,C,D,E,F = map(int,input().split())

waters = set()
for a in range(0,F+1,100*A):
    for b in range(0,F+1,100*B):
        if a+b > F:
            break
        waters.add(a+b)
waters.remove(0)

sugars = set()
for c in range(0,F+1,C):
    for d in range(0,F+1,D):
        if c+d > F:
            break
        sugars.add(c+d)

best_r = -1
best_w = best_s = 0

for w in waters:
    for s in sugars:
        if w+s > F: continue
        if E*w < s*100: continue
        r = s / (w+s)
        if r > best_r:
            best_r = r
            best_s = s
            best_w = w
print(best_w+best_s, best_s)