N = int(input())
Axl = []
Ayl = []
Bxl = []
Byl = []
for i in range(N):
    Ax, Ay = map(int,input().split())
    Axl += [Ax]
    Ayl += [Ay]
for i in range(N):
    Bx, By = map(int,input().split())
    Bxl += [Bx]
    Byl += [By]

gAx = 0
gAy = 0
gBx = 0
gBy = 0
for i in range(N):
    gAx += Axl[i]/N
    gAy += Ayl[i]/N
    gBx += Bxl[i]/N
    gBy += Byl[i]/N

lA = 0
lB = 0

for i in range(N):
    lA += ((Axl[i] - gAx)**(2) + (Ayl[i] - gAy)**(2))**(1/2)
    lB += ((Bxl[i] - gBx)**(2) + (Byl[i] - gBy)**(2))**(1/2)

print(lB/lA)