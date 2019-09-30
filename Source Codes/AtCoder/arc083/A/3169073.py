import sys
sys.setrecursionlimit(10**9)
f = lambda: map(int,input().split())

a,b,c,d,melt,mass = f()
wat = []
for i in range(mass//100//a+1):
    for j in range(mass//100//b+1):
        if i*a + j*b <= mass/100:
            wat.append((i*a + j*b)*100)
        else:
            break
sug = []
for i in range(mass//c+1):
    for j in range(mass//d+1):
        if i*c + j*d <= mass:
            sug.append(i*c + j*d)
        else:
            break
ans = [0,0]
cons = -float('inf')
for s in sug:
    for w in wat:
        if w > 0 and s/w > cons and s+w <= mass and s <= w*melt/100:
            cons = s/w
            ans = [s+w,s]
print(*ans)