w, h, n = map(int,input().split())
x1 = []
x2 = []
y3 = []
y4 = []
for i in range(n):
    x, y, a = map(int,input().split())
    if a == 1:
        x1.append(x)
    elif a == 2:
        x2.append(x)
    elif a == 3:
        y3.append(y)
    else:
        y4.append(y)

for t in [x1,y3]:
    if not t:
        t.append(0)
if not x2:
    x2.append(w)
if not y4:
    y4.append(h)

if max(x1) >= min(x2) or max(y3) >= min(y4):
    print(0)
    exit()
print((min(x2) - max(x1)) * (min(y4) - max(y3)))